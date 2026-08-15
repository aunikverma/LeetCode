class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int count = (nums[0] == 0 ? 1 : 0);
        int xor_all = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                count += 1;
            }
            xor_all ^= nums[i];
        }
        // if all elements are zero
        if (xor_all == 0 && count == n) {
            return 0;
        }
        // if all xor is zero remove one else whole array is good
        return (xor_all > 0 ? n : n - 1);
    }
};