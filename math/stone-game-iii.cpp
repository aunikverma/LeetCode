class Solution {
public:
    int n;
    int solve(int i, vector<int>& stones, vector<int>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != INT_MIN) {
            return dp[i];
        }
        dp[i] = INT_MIN;
        dp[i] = max(dp[i], stones[i] - solve(i + 1, stones, dp));
        if (i + 1 < n) {
            dp[i] = max(dp[i], stones[i] + stones[i + 1] - solve(i + 2, stones, dp));
        }
        if (i + 2 < n) {
            dp[i] = max(dp[i], stones[i] + stones[i + 1] + stones[i + 2] - solve(i + 3, stones, dp));
        }
        return dp[i];
    }

    string stoneGameIII(vector<int>& stones) {
        n = stones.size();
        vector<int> dp(n + 1, INT_MIN);
        int ans = solve(0, stones, dp);
        if (ans == 0) {
            return "Tie";
        }
        return (ans > 0 ? "Alice" : "Bob");
    }
};