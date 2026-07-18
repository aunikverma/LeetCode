class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0 || grid[0][0] != 0 || grid[m - 1][n - 1] != 0) {
            return -1; // base case
        }
        vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                   {0, 1},   {1, -1}, {1, 0},  {1, 1}};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // distance
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        dist[0][0] = 1;
        pq.push({1, {0, 0}}); // start
        while (!pq.empty()) {
            auto [d, points] = pq.top();
            auto [i, j] = points;
            pq.pop();
            for (auto& k : dir) {
                int r = i + k[0];
                int c = j + k[1];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 0 &&
                    d + 1 < dist[r][c]) {
                    dist[r][c] = d + 1; // since w = 1 for all edge
                    pq.push({d + 1, {r, c}});
                }
            }
        }
        if (dist[m - 1][n - 1] != INT_MAX) {
            return dist[m - 1][n - 1];
        }
        return -1;
    }
};