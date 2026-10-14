class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0)
        {
            return;
        }
        visited[i][j] = true;
        dfs(i + 1,j,grid,visited);
        dfs(i - 1,j,grid,visited);
        dfs(i,j + 1,grid,visited);
        dfs(i,j - 1,grid,visited);
    }
    int countIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (countIslands(grid) != 1) {
            return 0; // no  island
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] =
                        0; // changing this edge increase components or not
                    if (countIslands(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};