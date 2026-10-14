class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // maximum window having target sum = (sum - x);
        if (x > sum) {
            return -1;
        }
        int target = (sum - x);
        int window = INT_MIN;
        int l = 0;
        sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target) {
                sum -= nums[l];
                l++;
            }
            if (sum == target) {
                window = max(window, r - l + 1);
            }
        }
        return (window != INT_MIN ? (n - window) : -1);
    }
};