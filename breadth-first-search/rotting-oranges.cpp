class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q; // pairs of rotten orange
        int fresh = 0;           // fresh oranges
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if(fresh == 0){
            return 0; //base case
        }
        int minutes = 0; // time in rotting all orange
        while (!q.empty()) {
            int n1 = q.size();
            while (n1) {
                auto [i, j] = q.front();
                q.pop();
                for (auto& d : dir) {
                    int r = i + d[0], c = j + d[1];
                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;
                    }
                }
                n1--;
            }
            if (!q.empty()) {
                minutes++;
            }
        }
        return (fresh == 0) ? minutes : -1;
    }
};