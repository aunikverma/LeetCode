class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;                              // start
        priority_queue<P, vector<P>, greater<P>> pq; // min heap
        pq.push({0, {0, 0}});                        // src
        while (!pq.empty()) {
            auto [diff, points] = pq.top();
            auto [x, y] = points;
            pq.pop();
            if (x == m - 1 && y == n - 1) {
                return diff; //since it will not go lower further
            }
            for (auto& d : dir) {
                int r = x + d[0], c = y + d[1];
                if (r >= 0 && r < m && c >= 0 && c < n) {
                    int abs_diff = abs(h[x][y] - h[r][c]);
                    int max_diff = max(abs_diff, diff);
                    if (dist[r][c] > max_diff) {
                        dist[r][c] = max_diff;
                        pq.push({max_diff, {r, c}});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};

// - Effort between two cells: abs(heights[x1][y1] - heights[x2][y2])
// - Path effort: The maximum of all such efforts along the path
// - Goal: Minimize the maximum effort from start to en
