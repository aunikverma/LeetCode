class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    // directions
    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},  {2, {{1, 0}, {-1, 0}}},
        {3, {{0, -1}, {1, 0}}},  {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}}, {6, {{-1, 0}, {0, 1}}}};

    bool dfs(int i, int j, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) {
            return true;
        }
        visited[i][j] = true;
        for (auto& d : directions[grid[i][j]]) {
            int n_i = i + d[0];
            int n_j = j + d[1];

            if (n_i < 0 || n_i >= m || n_j < 0 || n_j >= n ||
                visited[n_i][n_j]) {
                continue;
            }
            // can we go back
            for (auto& back : directions[grid[n_i][n_j]]) {
                int p_i = n_i + back[0];
                int p_j = n_j + back[1];
                if (p_i == i && p_j == j) {
                    if (dfs(n_i, n_j, grid)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // visited
        visited.assign(m, vector<bool>(n, false));
        return dfs(0, 0, grid);
    }
};
