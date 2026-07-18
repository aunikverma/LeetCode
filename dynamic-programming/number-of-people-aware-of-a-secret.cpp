class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        long long j = 0, mod = 1000000007; // j  = share
        for (int i = 2; i <= n; i++) {
            if (i - delay > 0) {
                j = (j + dp[i - delay]) % mod;
            }
            if (i - forget > 0) {
                j = (j - dp[i - forget] + mod) % mod;
            }
            dp[i] = j;
        }
        long long ans = 0; // no of people who knows secret
        for (int i = n - forget + 1; i <= n; i++) {
            ans = (ans + dp[i]) % mod;
        }
        return (int)ans;
    }
};