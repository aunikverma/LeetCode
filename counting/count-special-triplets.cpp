class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> right;
        for (int i : nums) {
            right[i]++;
        }
        unordered_map<int, int> left;
        const int mod = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] << 1; // 2 * nums[i]
            right[nums[i]] -= 1;
            if (left.find(x) != left.end() && right.find(x) != right.end()) {
                ans = (ans + (1LL * left[x] * right[x]) % mod) % mod;
            }
            left[nums[i]]++;
        }
        return ans;
    }
};