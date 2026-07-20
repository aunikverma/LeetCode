class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (k == 0) {
            return grid;
        }
        int rows = grid.size(), cols = grid[0].size();
        int n = rows * cols;
        k = k % n;
        // reverse lambda function
        auto reverse = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / cols][i % cols], grid[j / cols][j % cols]);
                i++;
                j--;
            }
        };
        // similarly like rotate array
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
        return grid;
    }
};