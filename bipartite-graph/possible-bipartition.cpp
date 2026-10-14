class Solution {
private:
    bool dfs(int i, int curr_color, vector<int>& color,
             unordered_map<int, list<int>>& adj) {
        color[i] = curr_color;
        for (auto& j : adj[i]) {
            if (color[i] == color[j]) {
                return false; // adjacent node with color
            }
            if (color[j] == -1) {
                int to_color = 1 - curr_color;
                if (!dfs(j, to_color, color, adj)) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, list<int>> adj;
        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]); // undirected graph
        }
        vector<int> color(n + 1, -1); // color
        for (int i = 1; i < n; i++) {
            if (color[i] == -1) // red - 1,blue - 0
            {
                if (!dfs(i, 1, color, adj)) // start with red
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// to check whether graph is bipartite or not