class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < k; i++) {
            // swapping to i to i + 1
            for (int i = 0; i < m; i++) {
                int last = grid[i][n - 1];
                for (int j = n - 1; j >= 1; j--) {
                    grid[i][j] = grid[i][j - 1];
                }
                grid[i][0] = last;
            }
            // now first col j to j + 1
            int last = grid[m - 1][0];
            for (int i = m - 1; i >= 1; i--) {
                grid[i][0] = grid[i - 1][0];
            }
            grid[0][0] = last;
        }
        return grid;
    }
};