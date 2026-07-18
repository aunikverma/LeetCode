class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(3, INT_MIN / 2)));
        // from base case
        for (int k = 0; k <= 2; k++) {
            if (coins[m - 1][n - 1] < 0 && k > 0) {
                dp[m - 1][n - 1][k] = 0;
            } else {
                dp[m - 1][n - 1][k] = coins[m - 1][n - 1];
            }
        }
        // filling
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int k = 0; k <= 2; k++) {
                    if (i == m - 1 && j == n - 1) {
                        continue;
                    }
                    // normal
                    int right = (j + 1 < n ? dp[i][j + 1][k] : (INT_MIN / 2));
                    int down = (i + 1 < m ? dp[i + 1][j][k] : (INT_MIN / 2));
                    int take = coins[i][j] + max(right, down);
                    // we can neutralize here
                    int skip = (INT_MIN / 2);
                    if (coins[i][j] < 0 && k > 0) {
                        int right =
                            (j + 1 < n ? dp[i][j + 1][k - 1] : (INT_MIN / 2));
                        int down =
                            (i + 1 < m ? dp[i + 1][j][k - 1] : (INT_MIN / 2));
                        skip = max(right, down);
                    }
                    dp[i][j][k] = max(take, skip);
                }
            }
        }
        return dp[0][0][2];
    }
};