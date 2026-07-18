class Solution {
private:
    bool dfs(int node, int curr_color, vector<int>& color,
             vector<vector<int>>& adj) {
        color[node] = curr_color;
        for (int i : adj[node]) {
            if (color[i] == color[node]) // adjacent node cannot of same color
            {
                return false;
            }
            if (color[i] == -1) {
                int color_i = 1 - curr_color;
                if (dfs(i, color_i, color, adj) == false) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);   // we try to color all nodes by 2 color
        for (int i = 0; i < n; i++) // red - 1,blue - 0
        {
            if (color[i] == -1) {
                if (dfs(i, 1, color, adj) == false) // start with red
                {
                    return false;
                }
            }
        }
        return true;
    }
};