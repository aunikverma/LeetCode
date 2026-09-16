class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int n, int k, int i, vector<vector<int>>& dp) {
        if (i >= n) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        // skip this point
        int skip = solve(n, k, i + 1, dp) % mod;
        int take = 0;
        for (int j = i + 1; j <= n - 1; j++) {
            take += solve(n, k - 1, j, dp) % mod;
        }
        return dp[i][k] = (skip + take) % mod;
    }

    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(n, k, 0, dp);
    }
};
// since we can start from ith point and end at any j = i + 1 <= n - 1
// to make k segments
