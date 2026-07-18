class Solution {
private:
    bool bfs(int start, int target, unordered_map<int, list<int>>& adj) {
        unordered_map<int, bool> visited; // visited
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == target) {
                return true;
            }
            for (int i : adj[node]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            if (adj.count(u) && adj.count(v) && bfs(u, v, adj)) { //check for every edge before connecting
                return e;
            }
            adj[u].push_back(v);
            adj[v].push_back(u); // since undirected graph
        }
        return {};
    }
};