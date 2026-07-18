class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                sum++;
            } else if (nums[i] == 0) {
                ans = max(sum, ans);
                sum = 0;
            }
        }
        if (sum > 0) {
            ans = max(ans, sum);
        }
        return ans;
    }
};