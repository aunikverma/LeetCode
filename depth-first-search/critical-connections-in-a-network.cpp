class Solution {
private:
    void dfs(int node, int timer, int& parent, vector<bool>& visited,
             vector<int>& low, vector<int>& disc,
             unordered_map<int, list<int>>& adj, vector<vector<int>>& ans) {
        visited[node] = true;
        low[node] = disc[node] = timer++;
        for (auto& neigh : adj[node]) {
            if (neigh == parent) {
                continue; // do nothing
            }
            if (!visited[neigh]) {
                dfs(neigh, timer, node, visited, low, disc, adj, ans);
                // if backedge connection then update
                low[node] = min(low[node], low[neigh]);
                // check bridge
                if (low[neigh] > disc[node]) {
                    ans.push_back({node, neigh});
                }
            } else {
                // backedge
                low[node] = min(low[node], disc[neigh]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        unordered_map<int, list<int>> adj;
        for (auto& e : connections) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer = 0;
        vector<bool> visited(n, false);
        vector<int> low(n, -1);  // lowest earliest time
        vector<int> disc(n, -1); // dicovery time
        int parent = -1;
        vector<vector<int>> ans; // result
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, timer, parent, visited, low, disc, adj, ans);
            }
        }
        return ans;
    }
};