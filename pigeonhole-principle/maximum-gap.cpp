class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;
        for (int i = nums.size() - 1; i >= 1; i--) {
            int diff = nums[i] - nums[i - 1];
            maxi = max(diff, maxi);
        }
        return maxi;
    }
};