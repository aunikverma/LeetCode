class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // cols

        // row wise prefix sum
        vector<vector<int>> rowSum(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            rowSum[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                rowSum[i][j] = rowSum[i][j - 1] + grid[i][j];
            }
        }

        // col wise prefix sum
        vector<vector<int>> colSum(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            colSum[0][j] = grid[0][j];
            for (int i = 1; i < m; i++) {
                colSum[i][j] = colSum[i - 1][j] + grid[i][j];
            }
        }
        // try from largest side square
        for (int side = min(m, n); side >= 2; side--) {
            for (int i = 0; i + side - 1 < m; i++) {
                for (int j = 0; j + side - 1 < n; j++) {
                    // targetSum
                    int targetSum = rowSum[i][j + side - 1] -
                                    (j > 0 ? rowSum[i][j - 1] : 0);
                    bool allSame = true;
                    // check remaining rows
                    for (int r = i + 1; r < i + side; r++) {
                        int row_Sum = rowSum[r][j + side - 1] -
                                      (j > 0 ? rowSum[r][j - 1] : 0);
                        if (row_Sum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }
                    if (!allSame) {
                        continue; // not check cols
                    }
                    // check cols
                    for (int c = j; c < j + side; c++) {
                        int col_Sum = colSum[i + side - 1][c] -
                                      (i > 0 ? colSum[i - 1][c] : 0);
                        if (col_Sum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }
                    if (!allSame) {
                        continue; // not check diagonals
                    }
                    // check dig
                    int dig = 0, antidig = 0;
                    for (int k = 0; k < side; k++) {
                        dig += grid[i + k][j + k];
                        antidig += grid[i + k][j + side - 1 - k];
                    }
                    if (dig == targetSum && antidig == targetSum) {
                        return side; // max side square
                    }
                }
            }
        }
        return 1; // least size
    }
};