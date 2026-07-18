class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        for (vector<int>& i : queries) {
            int k = i[2];
            int v = i[3];
            for (int j = i[0]; j <= i[1]; j += k) {
                nums[j] = (1LL * nums[j] * v) % mod;
            }
        }
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};