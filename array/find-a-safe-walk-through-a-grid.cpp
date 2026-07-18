class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        // directions
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // result vector(stores min health)
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = grid[0][0];
        // health-node
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        // 0-1 BFS
        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();
            int cost = result[i][j];
            for (auto& d : dir) {
                int r = i + d[0];
                int c = j + d[1];

                if (r >= 0 && r < m && c >= 0 && c < n) {
                    if (cost + grid[r][c] < result[r][c]) {
                        result[r][c] = cost + grid[r][c];

                        if (grid[r][c] == 0) {
                            dq.push_front({r, c});
                        } else {
                            dq.push_back({r, c});
                        }
                    }
                }
            }
        }
        // min to reach (m - 1,n - 1)
        int x = result[m - 1][n - 1];
        return (health - x > 0);
    }
};
