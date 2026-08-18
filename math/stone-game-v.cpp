class Solution {
public:
    int solveTab(vector<int>& stones) {
        int n = stones.size();
        // prefix sum array
        vector<int> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int l = n - 1; l >= 0; l--) {
            for (int r = 0; r < n; r++) {
                if (l >= r) {
                    continue;
                }
                for (int mid = l; mid <= r - 1; mid++) {
                    int left_sum =
                        prefix[mid] - (l - 1 >= 0 ? prefix[l - 1] : 0);
                    int right_sum = prefix[r] - (mid >= 0 ? prefix[mid] : 0);

                    if (left_sum > right_sum) {
                        dp[l][r] = max(dp[l][r], right_sum + dp[mid + 1][r]);
                    } else if (right_sum > left_sum) {
                        dp[l][r] = max(dp[l][r], left_sum + dp[l][mid]);
                    } else {
                        dp[l][r] = max(dp[l][r], right_sum + dp[mid + 1][r]);
                        dp[l][r] = max(dp[l][r], left_sum + dp[l][mid]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }

    int stoneGameV(vector<int>& stones) { 
        return solveTab(stones); 
    }
};