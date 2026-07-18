class Solution {
public:
    int m, n;

    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int len = 1;
        if (j + 1 < n && grid[i][j + 1] > grid[i][j]) {
            len = max(len, 1 + solve(i, j + 1, grid, dp));
        }
        if (j - 1 >= 0 && grid[i][j - 1] > grid[i][j]) {
            len = max(len, 1 + solve(i, j - 1, grid, dp));
        }
        if (i + 1 < m && grid[i + 1][j] > grid[i][j]) {
            len = max(len, 1 + solve(i + 1, j, grid, dp));
        }
        if (i - 1 >= 0 && grid[i - 1][j] > grid[i][j]) {
            len = max(len, 1 + solve(i - 1, j, grid, dp));
        }
        return dp[i][j] = len;
    }

    int longestIncreasingPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = solve(i, j, grid, dp);
                ans = max(ans, len);
            }
        }
        return ans;
    }
};