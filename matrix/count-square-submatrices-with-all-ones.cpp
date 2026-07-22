class Solution {
public:
    int m, n;
    int solveTabSpace(vector<vector<int>>& matrix) {
        vector<int> curr(n, 0);
        vector<int> next(n, 0);

        int ans = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == 1) {
                    if (i == m - 1 || j == n - 1) {
                        curr[j] = 1;
                    } else {
                        curr[j] =
                            1 + min(next[j], min(curr[j + 1], next[j + 1]));
                    }
                    ans += curr[j];
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return ans;
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        return solveTabSpace(matrix);
    }
};