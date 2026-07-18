class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // Check which side is sorted
            if (nums[l] <= nums[mid]) { // Left side is sorted
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // Target is in the left half
                } else {
                    l = mid + 1; // Target is in the right half
                }
            } else { // Right side is sorted
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1; // Target is in the right half
                } else {
                    r = mid - 1; // Target is in the left half
                }
            }
        }
        return -1;
    }
};