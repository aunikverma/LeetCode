class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[j] - nums[i]) <= target && dp[j] != INT_MIN) {
                    int temp = 1 + dp[j];
                    dp[i] = max(dp[i], temp);
                }
            }
        }
        return (dp[0] < 0 ? -1 : dp[0]);
    }
};