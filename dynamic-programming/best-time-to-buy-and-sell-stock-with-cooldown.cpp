class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        int not_take = solve(i + 1, buy, prices, dp);
        int take = -1;
        if (buy) {
            take = solve(i + 2, 1 - buy, prices, dp) + prices[i];
        } else {
            take = solve(i + 1, 1 - buy, prices, dp) - prices[i];
        }
        return dp[i][buy] = max(take, not_take);
    }

    int solveTabSpace(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        vector<int> next1(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int not_take = next[buy];
                int take = -1;
                if (buy) {
                    take = next1[1 - buy] + prices[i];
                } else {
                    take = next[1 - buy] - prices[i];
                }
                curr[buy] = max(take, not_take);
            }
            next1 = next;
            next = curr;
        }
        return curr[0];
    }

    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return solve(0, 0, prices, dp);
        return solveTabSpace(prices);
    }
};