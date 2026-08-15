class Solution {
public:
    unordered_map<long long, int> dp;

    int solve(int i, int val, vector<int>& nums) {
        if (i >= nums.size()) {
            return (val > 0 ? 0 : INT_MIN);
        }
        long long key = ((long long)i << 32) ^ val;
        if (dp.count(key)) {
            return dp[key];
        }
        // take nums[i]
        int n_val = (val == -1 ? nums[i] : (val ^ nums[i]));
        int take = 1 + solve(i + 1, n_val, nums);
        // skip nums[i]
        int not_take = solve(i + 1, val, nums);
        return dp[key] = max(take, not_take);
    }

    int longestSubsequence(vector<int>& nums) {
        dp.clear();
        return max(0, solve(0, -1, nums));
    }
};
