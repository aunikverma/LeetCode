class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        k -= 1;
        int ans = INT_MAX;
        while (k < nums.size()) {
            int temp = nums[k] - nums[i];
            ans = min(temp, ans);
            i++;
            k++;
        }
        return ans;
    }
};