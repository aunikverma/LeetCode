class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                int c = abs(nums[i] - nums[0]);
                ans = max(ans, c);
            }
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};