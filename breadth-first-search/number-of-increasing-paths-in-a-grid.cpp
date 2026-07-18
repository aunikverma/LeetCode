class Solution {
public:
    int m, n;
    int Mod = 1e9 + 7;

    int solve(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        long long ans = 1;
        if (j + 1 < n && grid[i][j + 1] > grid[i][j]) {
            ans += solve(i, j + 1, grid, dp);
        }
        if (j - 1 >= 0 && grid[i][j - 1] > grid[i][j]) {
            ans += solve(i, j - 1, grid, dp);
        }
        if (i + 1 < m && grid[i + 1][j] > grid[i][j]) {
            ans += solve(i + 1, j, grid, dp);
        }
        if (i - 1 >= 0 && grid[i - 1][j] > grid[i][j]) {
            ans += solve(i - 1, j, grid, dp);
        }
        return dp[i][j] = (ans % Mod);
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        long long ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = (ans + solve(i, j, grid, dp)) % Mod;
            }
        }
        return ans;
    }
};