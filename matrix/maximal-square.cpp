class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, int& maxi) {
        if (i >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }
        int right = solve(matrix, i, j + 1, maxi);
        int diagonal = solve(matrix, i + 1, j + 1, maxi);
        int down = solve(matrix, i + 1, j, maxi);

        if (matrix[i][j] == '1') {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        } else {
            return 0;
        }
    }

    int solveMemo(vector<vector<char>>& matrix, int i, int j,
                  vector<vector<int>>& dp, int& maxi) {
        if (i >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int right = solveMemo(matrix, i, j + 1, dp, maxi);
        int diagonal = solveMemo(matrix, i + 1, j + 1, dp, maxi);
        int down = solveMemo(matrix, i + 1, j, dp, maxi);

        if (matrix[i][j] == '1') {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return dp[i][j] = ans;
        } else {
            return dp[i][j] = 0;
        }
    }

    int solveTab(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return (maxi * maxi);
    }

    int solveTabSpace(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxi = 0;
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int right = curr[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];
                if (matrix[i][j] == '1') {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                } else {
                    // since we are updating curr every time
                    curr[j] = 0;
                }
            }
            // next now equals curr
            next = curr;
        }
        return (maxi * maxi);
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        // solve(matrix, 0, 0, maxi);
        // return (maxi * maxi);
        // int m = matrix.size(), n = matrix[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // solveMemo(matrix, 0, 0, dp, maxi);
        // return (maxi * maxi);
        // return solveTab(matrix);
        return solveTabSpace(matrix);
    }
};
// you have to check diagonal and left and right