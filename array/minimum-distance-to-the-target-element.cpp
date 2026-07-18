class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = 0, j = nums.size() - 1;
        int ans = INT_MAX;
        while (i <= j) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
            if (nums[j] == target) {
                ans = min(ans, abs(j - start));
            }
            i++;
            j--;
        }
        return ans;
    }
};