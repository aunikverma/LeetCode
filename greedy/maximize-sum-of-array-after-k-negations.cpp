class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++) {
            sort(nums.begin(), nums.end());
            nums[0] = nums[0] * -1;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        return sum;
    }
};