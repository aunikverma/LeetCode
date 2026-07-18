class Solution {
public:
    // int M, N;

    // int solve(int i, int j, vector<vector<int>>& dp) {
    //     if (i == M - 1 && j == N - 1) {
    //         return 1;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     // right
    //     int right = (j + 1 < N ? solve(i, j + 1, dp) : 0);
    //     // down
    //     int down = (i + 1 < M ? solve(i + 1, j, dp) : 0);
    //     return dp[i][j] = (right + down);
    // }

    int solveTab(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // base case
        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                // right
                int right = (j + 1 < n ? dp[i][j + 1] : 0);
                // down
                int down = (i + 1 < m ? dp[i + 1][j] : 0);
                dp[i][j] = (right + down);
            }
        }
        return dp[0][0];
    }

    int solveTabSpace(int m, int n) {
        vector<int> curr(n, 0);
        vector<int> next(n, 0);
        // base case
        curr[n - 1] = next[n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                // right
                int right = (j + 1 < n ? curr[j + 1] : 0);
                // down
                int down = (i + 1 < m ? next[j] : 0);
                curr[j] = (right + down);
            }
            next = curr;
        }
        return curr[0];
    }

    int uniquePaths(int m, int n) {
        // M = m;
        // N = n;
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        if (m == 1 && n == 1) {
            return 1;
        }
        // return solve(0, 0, dp);
        // return solveTab(m, n);
        return solveTabSpace(m, n);
    }
};