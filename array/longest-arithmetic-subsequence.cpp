class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int ans = 2;
        vector<unordered_map<int, int>> dp(n + 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int count = 2;
                if (dp[j].count(diff)) {
                    count = 1 + dp[j][diff];
                }
                // update ans
                dp[i][diff] = max(dp[i][diff], count);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};