class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (k == 0) {
            return grid;
        }
        int m = grid.size(), n = grid[0].size();
        vector<int> rotate(m * n, 0);
        // fill rotate
        int ind = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotate[ind++] = grid[i][j];
            }
        }
        // rotate k times
        k = k % (m * n);
        reverse(rotate.begin(), rotate.end());
        reverse(rotate.begin(), rotate.begin() + k);
        reverse(rotate.begin() + k, rotate.end());
        // fill back to the grid
        ind = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = rotate[ind++];
            }
        }
        return grid;
    }
};