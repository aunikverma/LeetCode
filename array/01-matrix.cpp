class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        // Start BFS from all 0s
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        // Multi-source BFS
        //start from all zeros update -1 with abs 1 diff
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& d : dir) {
                int r = i + d[0], c = j + d[1];
                if (r >= 0 && r < m && c >= 0 && c < n && dist[r][c] == -1) {
                    dist[r][c] = dist[i][j] + 1;
                    q.push({r, c});
                }
            }
        }
        return dist;
    }
};