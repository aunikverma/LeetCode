class Solution {
private:
    bool check(vector<int>& nums, int l, int r) {
        for (int i = l + 1; i < r; i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) {
            return false;
        }
        for (int i = 0; i <= n - 2 * k; i++) {
            if (check(nums, i, i + k) && check(nums, i + k, i + 2 * k)) {
                return true;
            }
        }
        return false;
    }
};