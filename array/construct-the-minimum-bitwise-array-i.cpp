class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool found = false;
            //least prime
            if (nums[i] == 2) {
                ans.push_back(-1);
                continue;
            }
            for (int j = 0; j < 32; j++) {
                // set bit
                if ((nums[i] & (1 << j)) > 0) {
                    continue;
                }
                int prev = j - 1;
                // set it to 0
                int x = nums[i] ^ (1 << (j - 1)); // using xor opn
                ans.push_back(x);
                found = true;
                break;
            }
            if (!found) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};