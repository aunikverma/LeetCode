class Solution {
public:
    int solve(vector<int>& obstacles, int curr_lane, int curr_pos,
              vector<vector<int>>& dp) {
        int n = obstacles.size() - 1;
        // base case
        if (curr_pos == n) {
            return 0;
        }
        if (dp[curr_lane][curr_pos] != -1) {
            return dp[curr_lane][curr_pos];
        }
        if (obstacles[curr_pos + 1] != curr_lane) {
            return dp[curr_lane][curr_pos] =
                       solve(obstacles, curr_lane, curr_pos + 1, dp);
        } else {
            // now we have to do sideways jump
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (curr_lane != i && obstacles[curr_pos] != i) {
                    ans = min(ans, 1 + solve(obstacles, i, curr_pos, dp));
                }
            }
            return dp[curr_lane][curr_pos] = ans;
        }
    }

    int solveTab(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), INT_MAX));
        // base case
        for (int i = 0; i < 4; i++) {
            dp[i][n] = 0;
        }
        for (int curr_pos = n - 1; curr_pos >= 0; curr_pos--) {
            for (int curr_lane = 1; curr_lane <= 3; curr_lane++) {
                if (obstacles[curr_pos + 1] != curr_lane) {
                    dp[curr_lane][curr_pos] = dp[curr_lane][curr_pos + 1];
                } else {
                    // now we have to do sideways jump
                    int ans = INT_MAX;
                    for (int i = 1; i <= 3; i++) {
                        if (curr_lane != i && obstacles[curr_pos] != i) {
                            // since bottom up may dp[i][curr_pos] == int_max
                            ans = min(ans, 1 + dp[i][curr_pos + 1]);
                        }
                    }
                    dp[curr_lane][curr_pos] = ans;
                }
            }
        }
        return min(dp[2][0], 1 + min(dp[1][0], dp[3][0]));
    }
    int solveTabSpace(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);
        // base case
        for (int i = 0; i < 4; i++) {
            next[i] = 0;
        }
        for (int curr_pos = n - 1; curr_pos >= 0; curr_pos--) {
            for (int curr_lane = 1; curr_lane <= 3; curr_lane++) {
                if (obstacles[curr_pos + 1] != curr_lane) {
                    curr[curr_lane] = next[curr_lane];
                } else {
                    // now we have to do sideways jump
                    int ans = INT_MAX;
                    for (int i = 1; i <= 3; i++) {
                        if (curr_lane != i && obstacles[curr_pos] != i) {
                            // since bottom up may dp[i][curr_pos] == int_max
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[curr_lane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], 1 + min(next[1], next[3]));
    }

    int minSideJumps(vector<int>& obstacles) {
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return solve(obstacles, 2, 0, dp);
        // return solveTab(obstacles);
        return solveTabSpace(obstacles);
    }
};