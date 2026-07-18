class Solution {
public:
    int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        int take = 0;
        if (buy) {
            take = solve(prices, i + 1, 0, dp) - prices[i];
        } else {
            take = solve(prices, i + 1, 1, dp) + prices[i];
        }
        int not_take = solve(prices, i + 1, buy, dp);
        return dp[i][buy] = max(take, not_take);
    }

    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                int take = 0;
                if (buy) {
                    take = dp[i + 1][1 - buy] - prices[i];
                } else {
                    take = dp[i + 1][1 - buy] + prices[i];
                }
                int not_take = dp[i + 1][buy];
                dp[i][buy] = max(take, not_take);
            }
        }
        return dp[0][1];
    }

    int solveTabSpace(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                int take = 0;
                if (buy) {
                    take = next[1 - buy] - prices[i];
                } else {
                    take = next[1 - buy] + prices[i];
                }
                int not_take = next[buy];
                curr[buy] = max(take, not_take);
            }
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return solve(prices, 0, 1, dp);
        // return solveTab(prices);
        return solveTabSpace(prices);
    }
};
// 1 buy -> skip or buy
//  0 sell -> skip or sell