class Solution {
public:
    int dp[20][20][2];

    int solve(int i, int j, int turn, vector<int>& nums) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j][turn] != -1) {
            return dp[i][j][turn];
        }
        if (turn) {
            int left = nums[i] + solve(i + 1, j, 1 - turn, nums);
            int right = nums[j] + solve(i, j - 1, 1 - turn, nums);
            return dp[i][j][turn] = max(left, right);
        } else {
            if (nums[i] > nums[j]) {
                return dp[i][j][turn] =
                           (-nums[i] + solve(i + 1, j, 1 - turn, nums));
            } else {
                return dp[i][j][turn] =
                           (-nums[j] + solve(i, j - 1, 1 - turn, nums));
            }
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, nums.size() - 1, 1, nums);
        return (ans >= 0);
    }
};