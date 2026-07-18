class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [time, point] = pq.top();
            pq.pop();
            int i = point.first;
            int j = point.second;
            if (i == n - 1 && j == n - 1) return time; //if reached at destination

            if (visited[i][j]) continue;
            visited[i][j] = true;
            for (auto d : dir) {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
                    pq.push({max(time, grid[x][y]), {x, y}});
                }
            }
        }
        return -1;
    }
};