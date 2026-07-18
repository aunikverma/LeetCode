class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int suff = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1]; // prefix mul leaving 0th index
        }
        for (int j = n - 2; j >= 0; j--) {
            suff = suff * nums[j + 1]; // mul from behind then into ans
            ans[j] *= suff;
        }
        return ans;
    }
};