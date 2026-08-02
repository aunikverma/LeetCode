class Solution {
public:
    int dp[20][20];

    int solve(int i, int j, vector<int>& nums) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return nums[i];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int left = nums[i] - solve(i + 1, j, nums);
        int right = nums[j] - solve(i, j - 1, nums);
        return dp[i][j] = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, nums.size() - 1, nums);
        return (ans >= 0);
    }
};