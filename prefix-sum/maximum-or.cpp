class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        vector<int> suffix(n + 1, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] | nums[i - 1];         // prefix or
            suffix[n - i - 1] = suffix[n - i] | nums[n - i]; // suffix or
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, prefix[i] | (long long)nums[i] << k | suffix[i]); // applyin operation on i k times
        }
        return ans;
    }
};