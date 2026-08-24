class Solution {
public:
    int n;

    int solve(int i, vector<int>& prefix, vector<int>& dp) {
        if (i == n - 1) {
            return prefix[i];
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int take = prefix[i] - solve(i + 1, prefix, dp);
        int skip = solve(i + 1, prefix, dp);
        return dp[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        vector<int> dp(n, -1);
        return solve(1, prefix, dp);
    }
};