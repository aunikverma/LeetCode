class Solution {
public:
    long long solve(vector<int>& prices, int i, int k, int Case,
                    vector<vector<vector<long long>>>& dp) {
        if (i >= prices.size()) {
            // no imcomplete transaction
            if (Case == 0) {
                return 0;
            }
            return INT_MIN;
        }
        if (dp[i][k][Case] != -1) {
            return dp[i][k][Case];
        }
        long long take = INT_MIN;
        if (k > 0) {
            if (Case == 1) {
                // sell
                take = solve(prices, i + 1, k - 1, 0, dp) + prices[i];
            } else if (Case == 2) {
                take = solve(prices, i + 1, k - 1, 0, dp) - prices[i];
            } else {
                take = max(solve(prices, i + 1, k, 1, dp) - prices[i],
                           solve(prices, i + 1, k, 2, dp) + prices[i]);
            }
        }
        long long not_take = solve(prices, i + 1, k, Case, dp);
        return dp[i][k][Case] = max(take, not_take);
    }

    long long solveTab(vector<int>& prices, int K) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(K + 1, vector<long long>(3, INT_MIN)));
        // base case
        for (int k = 0; k <= K; k++) {
            dp[n][k][0] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k <= K; k++) {
                for (int Case = 0; Case <= 2; Case++) {
                    long long take = INT_MIN;
                    if (k > 0) {
                        if (Case == 1) {
                            // sell
                            take = dp[i + 1][k - 1][0] + prices[i];
                        } else if (Case == 2) {
                            take = dp[i + 1][k - 1][0] - prices[i];
                        } else {
                            take = max(dp[i + 1][k][1] - prices[i],
                                       dp[i + 1][k][2] + prices[i]);
                        }
                    }
                    long long not_take = dp[i + 1][k][Case];
                    dp[i][k][Case] = max(take, not_take);
                }
            }
        }
        return dp[0][K][0];
    }

    long long solveTabSpace(vector<int>& prices, int K) {
        int n = prices.size();
        vector<vector<long long>> curr(K + 1, vector<long long>(3, INT_MIN));
        vector<vector<long long>> next(K + 1, vector<long long>(3, INT_MIN));
        for (int k = 0; k <= K; k++) {
            next[k][0] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k <= K; k++) {
                for (int Case = 0; Case <= 2; Case++) {
                    long long take = INT_MIN;
                    if (k > 0) {
                        if (Case == 1) {
                            // sell
                            take = next[k - 1][0] + prices[i];
                        } else if (Case == 2) {
                            take = next[k - 1][0] - prices[i];
                        } else {
                            take = max(next[k][1] - prices[i],
                                       next[k][2] + prices[i]);
                        }
                    }
                    long long not_take = next[k][Case];
                    curr[k][Case] = max(take, not_take);
                }
            }
            next = curr;
        }
        return curr[K][0];
    }

    long long maximumProfit(vector<int>& prices, int k) {
        // int n = prices.size();
        // vector<vector<vector<long long>>> dp(
        //     n + 1, vector<vector<long long>>(k + 1, vector<long long>(3,
        //     -1)));
        // return solve(prices, 0, k, 0, dp);
        // return solveTab(prices, k);
        return solveTabSpace(prices, k);
    }
};
// case 0 buy or shortsell
// case 1 sell
// case 2 buy