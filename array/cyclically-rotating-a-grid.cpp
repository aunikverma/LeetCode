class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;
        for (int l = 0; l < layers; l++) {
            vector<int> arr;
            int top = l, left = l;
            int bottom = m - l - 1, right = n - l - 1;

            // first col
            for (int i = top; i <= bottom; i++) {
                arr.push_back(grid[i][left]);
            }
            // last row
            for (int j = left + 1; j <= right; j++) {
                arr.push_back(grid[bottom][j]);
            }
            // last col
            for (int i = bottom - 1; i >= top; i--) {
                arr.push_back(grid[i][right]);
            }
            // first row
            for (int j = right - 1; j > left; j--) {
                arr.push_back(grid[top][j]);
            }

            // now rotation
            int k1 = k % arr.size();
            reverse(arr.begin(), arr.end());
            reverse(arr.begin(), arr.begin() + k1);
            reverse(arr.begin() + k1, arr.end());

            // now fill the layer
            // first col
            int ind = 0;
            for (int i = top; i <= bottom; i++) {
                grid[i][left] = arr[ind++];
            }
            // last row
            for (int j = left + 1; j <= right; j++) {
                grid[bottom][j] = arr[ind++];
            }
            // last col
            for (int i = bottom - 1; i >= top; i--) {
                grid[i][right] = arr[ind++];
            }
            // first row
            for (int j = right - 1; j > left; j--) {
                grid[top][j] = arr[ind++];
            }
        }
        return grid;
    }
};