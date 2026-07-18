class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        for (int i = 0; i < k; i++) {
            left += nums[i];
            right += nums[n - 1 - i];
        }
        return abs(right - left);
    }
};