class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size(); // rows,cols
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        // prefix[i][j] = sum of all elements in mat from top_left [0][0] to
        // [i][j]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] = (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0) +
                               mat[i][j];
            }
        }

        // lambda function
        auto sumSquare = [&](int i, int j, int r2, int c2) {
            int sum = prefix[r2][c2];
            if (i > 0) {
                sum -= prefix[i - 1][c2];
            }
            if (j > 0) {
                sum -= prefix[r2][j - 1];
            }
            if (i > 0 && j > 0) {
                sum += prefix[i - 1][j - 1];
            }
            return sum;
        };

        int best = 0; // side
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // offset for dig
                for (int k = best; k < min(m - i, n - j); k++) {
                    int r2 = i + k, c2 = j + k;
                    int sum = sumSquare(i, j, r2, c2);
                    if (sum <= threshold) {
                        best = max(best, k + 1);
                    } else {
                        break;
                    }
                }
            }
        }
        return best;
    }
};