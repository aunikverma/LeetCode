class Solution {
public:
    int solve(int i, int j, string& a, string& b, vector<vector<int>>& dp) {
        if (i >= a.length() || j >= b.length()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (a[i] == b[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, a, b, dp);
        }
        return dp[i][j] =
                   max(solve(i + 1, j, a, b, dp), solve(i, j + 1, a, b, dp));
    }

    int solveTab(string& a, string& b) {
        int m = a.length(), n = b.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }

    int solveTabSpace(string& a, string& b) {
        int m = a.length(), n = b.length();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }
        return curr[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int m = text1.length(), n = text2.length();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return solve(0, 0, text1, text2, dp);
        // return solveTab(text1, text2);
        return solveTabSpace(text1, text2);
    }
};