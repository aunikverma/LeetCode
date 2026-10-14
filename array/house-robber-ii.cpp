class Solution {
public:
    int solve(vector<int>& nums, int s, int e) {
        int n = s - e + 1;
        int next = max(nums[e], nums[e - 1]); // dp[i + 1]
        int next_n = nums[e];                 // dp[i + 2]
        for (int i = e - 2; i >= s; i--) {
            int take = nums[i] + next_n;
            int skip = next;
            next_n = next;
            next = max(take, skip);
        }
        return next;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};