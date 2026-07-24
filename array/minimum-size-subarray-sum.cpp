class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int size = INT_MAX;

        int left = 0, right = 0;
        for (int right = 0; right < n; right++) {
            // add in sum
            sum += nums[right];
            // try shrinking window
            while (sum >= target) {
                size = min(size, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (size != INT_MAX ? size : 0);
    }
};