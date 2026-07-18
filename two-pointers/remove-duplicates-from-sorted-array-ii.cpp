class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for (int i = 0; i < nums.size();) {
            int count = 0;
            int c = nums[i];
            while (i < n && nums[i] == c) {
                if (count < 2) {
                    arr.push_back(nums[i]);
                }
                count++;
                i++;
            }
        }
        int ans = arr.size();
        for (int i = 0; i < ans; i++) {
            nums[i] = arr[i];
        }
        return ans;
    }
};