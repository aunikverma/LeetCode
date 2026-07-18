class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
        int st = 0;
        int s = 1;
        for (int i : nums) {
            if (i & 1 == 1) {
                ans[s] = i;
                s += 2;
            } else {
                ans[st] = i;
                st += 2;
            }
        }
        return ans;
    }
};