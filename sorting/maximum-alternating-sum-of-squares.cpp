class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.rbegin(), nums.rend());
        long long ans = 0;
        int take = (n & 1 ? (n / 2) + 1 : n / 2);
        for (int i = 0; i < n; i++) {
            long long v = (nums[i] * nums[i]);
            ans += (i < take ? v : -v);
        }
        return ans;
    }
};