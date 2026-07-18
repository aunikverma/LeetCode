class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l + 1 < r && nums[l + 1] == nums[l]) {
                l++;
            }
            while (r - 1 > l && nums[r - 1] == nums[r]) {
                r--;
            }
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};