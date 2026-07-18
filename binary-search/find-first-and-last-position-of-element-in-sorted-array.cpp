class Solution {
private:
    int firstocc(vector<int> nums, int target) {
        int s = 0;//finding first occurence
        int e = nums.size() - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans = mid;
                e = mid - 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
    int lastocc(vector<int> nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;//finding last occurence
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans = mid;
                s = mid + 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, 0);
        ans[0] = firstocc(nums,target);
        ans[1] = lastocc(nums,target);
        return ans;
    }
};