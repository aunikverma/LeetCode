class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= (k + maxPts - 1))
            return 1.0; // edge case
        vector<double> dp(n + 1, 0);
        dp[0] = 1;
        double sum = 1, prob = 0;
        for (int l = 0, i = 1; i <= n; i++) {
            dp[i] = sum / maxPts;
            if (i < k) {
                sum += dp[i];
            } else {
                prob += dp[i];
            }
            if (i >= maxPts) {
                sum -= dp[l++];
            }
        }
        return prob;
    }
};