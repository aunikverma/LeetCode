class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // inserting cost[0] = 0
        costs.insert(costs.begin(), 0);
        vector<int> dp(n + 1, 1e9 + 7);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 3; k++) {
                int ind = i + k;
                if (ind <= n) {
                    int cost = costs[ind] + pow((ind - i), 2);
                    dp[i] = min(dp[i], cost + dp[ind]);
                }
            }
        }
        return dp[0];
    }
};