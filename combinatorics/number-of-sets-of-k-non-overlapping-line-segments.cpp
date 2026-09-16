class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfSets(int n, int K) {
        vector<vector<int>> dp(K + 1, vector<int>(n + 1, 0));
        // base case
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int k = 1; k <= K; k++) {
            // suffix sum
            vector<int> PrevRow(n + 1, 0);
            for (int x = n - 1; x >= 0; x--) {
                PrevRow[x] = (PrevRow[x + 1] + dp[k - 1][x]) % mod;
            }
            for (int i = n - 1; i >= 0; i--) {
                int skip = dp[k][i + 1] % mod;
                int take = PrevRow[i + 1];
                dp[k][i] = (skip + take) % mod;
            }
        }
        return dp[K][0];
    }
};
// since we can start from ith point and end at any j = i + 1 <= n - 1
// to make k segments
