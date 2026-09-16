class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfSets(int n, int K) {
        vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));
        // base case
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= K; k++) {
                long long skip = dp[i + 1][k] % mod;
                long long take = 0;
                for (int j = i + 1; j <= n - 1; j++) {
                    take += dp[j][k - 1] % mod;
                }
                dp[i][k] = (skip + take) % mod;
            }
        }
        return dp[0][K];
    }
};
// since we can start from ith point and end at any j = i + 1 <= n - 1
// to make k segments
