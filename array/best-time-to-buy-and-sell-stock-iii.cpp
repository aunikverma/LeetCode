class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int k,
              vector<vector<vector<int>>>& dp) {
        if (i >= prices.size() || k == 2) {
            return 0;
        }
        if (dp[i][buy][k] != -1) {
            return dp[i][buy][k];
        }
        int not_take = solve(prices, i + 1, buy, k, dp);
        int take = 0;
        if (buy) {
            take = solve(prices, i + 1, 1 - buy, k, dp) - prices[i];
        } else {
            take = solve(prices, i + 1, 1 - buy, k + 1, dp) + prices[i];
        }
        return dp[i][buy][k] = max(take, not_take);
    }

    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int k = 2; k >= 0; k--) {
                    int not_take = dp[i + 1][buy][k];
                    int take = 0;
                    if (buy) {
                        // Buy only if transactions left
                        if (k < 2) {
                            take = dp[i + 1][1 - buy][k] - prices[i];
                        }
                    } else {
                        // Sell only if transactions left
                        if (k < 2) {
                            take = dp[i + 1][1 - buy][k + 1] + prices[i];
                        }
                    }
                    dp[i][buy][k] = max(take, not_take);
                }
            }
        }
        return dp[0][1][0];
    }

    int solveTabSpace(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int k = 2; k >= 0; k--) {
                    int not_take = next[buy][k];
                    int take = 0;
                    if (buy) {
                        // Buy only if transactions left
                        if (k < 2) {
                            take = next[1 - buy][k] - prices[i];
                        }
                    } else {
                        // Sell only if transactions left
                        if (k < 2) {
                            take = next[1 - buy][k + 1] + prices[i];
                        }
                    }
                    curr[buy][k] = max(take, not_take);
                }
                next = curr;
            }
        }
        return curr[1][0];
    }

    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(2, -1)));
        // return solve(prices, 0, 1, 0, dp);
        // return solveTab(prices);
        return solveTabSpace(prices);
    }
};