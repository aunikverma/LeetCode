class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size(), m = mul.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int opn = m - 1; opn >= 0; opn--) {
            for (int left = opn; left >= 0; left--) {
                int l = (mul[opn] * nums[left]) + dp[opn + 1][left + 1];
                int r = (mul[opn] * nums[n - 1 - opn + left]) + dp[opn + 1][left];
                dp[opn][left] = max(l, r);
            }
        }
        return dp[0][0];
    }
};