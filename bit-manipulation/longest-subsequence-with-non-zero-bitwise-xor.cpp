class Solution {
public:
    int n;
    int solve(int i, int val, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size()) {
            if (val > 0) {
                return 0;
            } else {
                return INT_MIN;
            }
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        dp[i] = 0;
        int n_val = (val == -1 ? nums[i] : nums[i] ^ val);
        int take = 1 + solve(i + 1, n_val, nums, dp);
        int not_take = solve(i + 1, val, nums, dp);
        return dp[i] = max(take, not_take);
    }

    int longestSubsequence(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(0, -1, nums, dp);
    }
};