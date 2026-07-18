class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();    // row
        int n = heightMap[0].size(); // col
        priority_queue<PP, vector<PP>, greater<PP>> pq; // min heap {hieght,{i,j}} (boundary cells)
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // visited false

        // boundary
        for (int i = 0; i < m; i++) // leftmost  and rightmost cols
        {
            for (int j : {0, n - 1}) {
                pq.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int i = 0; i < n; i++) // upper  and down rows
        {
            for (int j : {0, m - 1}) {
                pq.push({heightMap[j][i], {j, i}});
                visited[j][i] = true;
            }
        }

        int water = 0;
        // now water
        while (!pq.empty()) {
            PP p = pq.top();
            pq.pop();
            int height = p.first;
            int i = p.second.first;  // row
            int j = p.second.second; // col

            for (vector<int>& v : dir) {
                int new_i = v[0] + i;
                int new_j = v[1] + j;
                if (new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && !visited[new_i][new_j]) {
                    water += max(height - heightMap[new_i][new_j], 0);
                    pq.push({max(height, heightMap[new_i][new_j]), {new_i, new_j}});
                    visited[new_i][new_j] = true;
                }
            }
        }
        return water;
    }
};