class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0;
        for (int i : nums) {
            if (i & 1) {
                odd++;
            } else {
                even++;
            }
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] & 1) {
                ans[i] = even;
                odd -= 1;
            } else {
                ans[i] = odd;
                even -= 1;
            }
        }
        return ans;
    }
};