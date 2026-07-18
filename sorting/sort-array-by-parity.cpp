class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int st = 0;
        int e = nums.size() - 1;
        for (int i : nums) {
            if (i & 1 == 1) {
                ans[e--] = i;
            } else {
                ans[st++] = i;
            }
        }
        return ans;
    }
};