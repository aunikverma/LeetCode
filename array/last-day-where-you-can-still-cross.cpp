class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<int>>& grid, int i, int j, int row, int col) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 1) {
            return false;
        }
        if (i == row - 1) {
            return true;
        }
        grid[i][j] = 1;
        for (auto& d : directions) {
            int new_i = i + d[0],
                new_j = j + d[1]; // travelling in all four directions
            if (dfs(grid, new_i, new_j, row, col)) {
                return true;
            }
        }
        return false;
    }
    bool canCross(vector<vector<int>>& cells, int mid, int row, int col) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i <= mid; i++) {
            int x = cells[i][0] - 1,
                y = cells[i][1] - 1; // filling water upto mid cells
            grid[x][y] = 1;
        }
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0 &&
                dfs(grid, 0, j, row,
                    col)) { // from first row can we reach to bottom
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0, r = cells.size() - 1;
        int lastday = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canCross(cells, mid, row,
                         col)) { // using binary search to find the last day
                lastday = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return lastday;
    }
};