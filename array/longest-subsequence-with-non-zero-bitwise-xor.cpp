class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0;
        int zeros = 0;
        for (int i : nums) {
            xor_all ^= i;
            zeros += (i == 0 ? 1 : 0);
        }
        if (xor_all == 0 && zeros == n) {
            return 0;
        }
        return (xor_all > 0 ? n : n - 1);
    }
};