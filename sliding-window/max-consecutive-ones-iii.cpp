class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int zeros = 0;
        int ans = 0;

        while (right < n) {
            if (nums[right] == 0) {
                zeros += 1;
            }
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros -= 1;
                }
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};