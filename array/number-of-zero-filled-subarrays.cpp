class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0;
        long long ans = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                long long c = 1;
                while (i + 1 < nums.size() && nums[i + 1] == 0) {
                    c++;
                    i++;
                }
                ans += (c * (c + 1)) / 2;
            }
            i++;
        }
        return ans;
    }
};