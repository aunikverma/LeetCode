class Solution {
private:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid,vector<vector<bool>>& visited, int& count) {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] ||
            grid[i][j] == 0) {
            return;
        }
        visited[i][j] = true;
        count++;
        dfs(i + 1, j, m, n, grid, visited, count);
        dfs(i - 1, j, m, n, grid, visited, count);
        dfs(i, j + 1, m, n, grid, visited, count);
        dfs(i, j - 1, m, n, grid, visited, count);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) { //same like no of islands
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // visited
        int ans = 0; // max area of island
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int count = 0; //instead of counting islands 
                    dfs(i, j, m, n, grid, visited, count);
                    ans = max(ans, count); //count max area
                }
            }
        }
        return ans;
    }
};