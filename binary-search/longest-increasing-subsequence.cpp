class Solution {
private:
    int solve(int prev, int index, vector<int>& nums, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[prev + 1][index] != -1) {
            return dp[prev + 1][index];
        }
        // skip current element
        int not_take = solve(prev, index + 1, nums, dp);
        // take current element 
        int take = 0;
        if (prev == -1 || nums[index] > nums[prev]) {
            take = 1 + solve(index, index + 1, nums, dp);
        }
        return dp[prev + 1][index] = max(take, not_take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(-1, 0, nums, dp);
    }
};