class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int Mod = 1e9 + 7;
        vector<vector<int>> curr(n + 1, vector<int>(k, 0));
        vector<vector<int>> next(n + 1, vector<int>(k, 0));
        // base case
        for (int sum = 0; sum < k; sum++) {
            if ((sum + grid[m - 1][n - 1]) % k == 0) {
                curr[n - 1][sum] = 1;
            }
        }
        // filling dp table
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int sum = 0; sum < k; sum++) {
                    if (i == m - 1 && j == n - 1) {
                        continue;
                    }
                    int new_sum = (sum + grid[i][j]) % k;
                    curr[j][sum] = (next[j][new_sum] + curr[j + 1][new_sum]) % Mod;
                }
            }
            next = curr;
        }
        return curr[0][0];
    }
};