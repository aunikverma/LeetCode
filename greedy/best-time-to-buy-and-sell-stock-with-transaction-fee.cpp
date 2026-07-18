class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, int fee,
              vector<vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        int not_take = solve(i + 1, buy, prices, fee, dp);
        int take = 0;
        if (buy) {
            take = solve(i + 1, 1 - buy, prices, fee, dp) + prices[i] - fee;
        } else {
            take = solve(i + 1, 1 - buy, prices, fee, dp) - prices[i];
        }
        return dp[i][buy] = max(take, not_take);
    }

    int solveTab(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int not_take = dp[i + 1][buy];
                int take = 0;
                if (buy) {
                    take = dp[i + 1][1 - buy] + prices[i] - fee;
                } else {
                    take = dp[i + 1][1 - buy] - prices[i];
                }
                dp[i][buy] = max(take, not_take);
            }
        }
        return dp[0][0];
    }

    int solveTabSpace(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int not_take = next[buy];
                int take = 0;
                if (buy) {
                    take = next[1 - buy] + prices[i] - fee;
                } else {
                    take = next[1 - buy] - prices[i];
                }
                curr[buy] = max(take, not_take);
            }
            next = curr;
        }
        return curr[0];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return solve(0, 0, prices, fee, dp);
        // return solveTab(prices, fee);
        return solveTabSpace(prices, fee);
    }
};