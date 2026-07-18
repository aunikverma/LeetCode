class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        // heights of water cells must be zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) // src and must be 0
                {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        // apply multi src bfs
        while (!q.empty()) {
            int n1 = q.size();
            while (n1) {
                auto [i, j] = q.front();
                q.pop();
                for (auto& d : dir) {
                    int r = i + d[0], c = j + d[1];
                    if (r >= 0 && r < m && c >= 0 && c < n &&
                        height[r][c] == -1) {
                        height[r][c] = height[i][j] + 1;
                        q.push({r, c});
                    }
                }
                n1--;
            }
        }
        return height;
    }
};