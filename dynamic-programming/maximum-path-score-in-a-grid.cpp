class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, INT_MIN)));
        // base case
        for (int cost = 0; cost <= k; cost++) {
            int new_cost = cost + (grid[m - 1][n - 1] == 0 ? 0 : 1);
            if (new_cost <= k) {
                dp[m - 1][n - 1][cost] = grid[m - 1][n - 1];
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cost = k; cost >= 0; cost--) {
                    if (i == m - 1 && j == n - 1) {
                        continue;
                    }
                    int new_cost = cost + (grid[i][j] == 0 ? 0 : 1);
                    if (new_cost > k) {
                        continue;
                    }
                    int right = dp[i][j + 1][new_cost];
                    int down = dp[i + 1][j][new_cost];
                    dp[i][j][cost] = max(right, down) + grid[i][j];
                }
            }
        }
        return (dp[0][0][0] < 0 ? -1 : dp[0][0][0]);
    }
};