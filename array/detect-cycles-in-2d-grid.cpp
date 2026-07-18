class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(int i, int j, int p_i, int p_j, vector<vector<char>>& grid) {
        if (visited[i][j]) {
            return true;
        }
        visited[i][j] = true;
        for (auto& d : dir) {
            int n_i = i + d[0];
            int n_j = j + d[1];
            if (n_i >= 0 && n_i < m && n_j >= 0 && n_j < n &&
                grid[i][j] == grid[n_i][n_j]) {
                if (n_i == p_i && n_j == p_j) {
                    continue;
                }
                if (dfs(n_i, n_j, i, j, grid)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool bfs(int i, int j, vector<vector<char>>& grid) {
        // i,j,p_i,p_j
        queue<tuple<int, int, int, int>> q;
        q.push({i, j, -1, -1});
        visited[i][j] = true;

        while (!q.empty()) {
            auto [i, j, p_i, p_j] = q.front();
            q.pop();
            for (auto& d : dir) {
                int n_i = i + d[0];
                int n_j = j + d[1];
                if (n_i >= 0 && n_i < m && n_j >= 0 && n_j < n &&
                    grid[i][j] == grid[n_i][n_j]) {
                    if (n_i == p_i && n_j == p_j) {
                        continue;
                    }
                    if (visited[n_i][n_j]) {
                        return true;
                    }
                    visited[n_i][n_j] = true;
                    q.push({n_i, n_j, i, j});
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // visited
        visited.assign(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // if (!visited[i][j] && dfs(i, j, -1, -1, grid)) {
                //     return true;
                // }
                if (!visited[i][j] && bfs(i, j, grid)) {
                    return true;
                }
            }
        }
        return false;
    }
};