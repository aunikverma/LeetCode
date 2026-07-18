class Solution {
public:
    int n;

    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= n - 1) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = 1e9;
        for (int k = 1; k <= nums[i]; k++) {
            ans = min(ans, 1 + solve(i + k, nums, dp));
        }
        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(0, nums, dp);
    }
};