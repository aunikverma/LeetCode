class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int count = 0;
        // prefix row
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                grid[i][j] += grid[i][j - 1];
            }
        }
        // prefix col
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 0; i < grid.size(); i++) {
                if (i > 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                if (grid[i][j] <= k) {
                    count++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};