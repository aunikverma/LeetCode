class Solution {
private:
    bool dfs(unordered_map<int, list<int>>& adj, vector<bool>& visited,
             int source, int destination) {
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        for (int neighbour : adj[source]) {
            if (!visited[neighbour]) {
                if (dfs(adj, visited, neighbour, destination)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, list<int>> adj;
        for (auto e : edges) // bidirectional
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);// visited
        return dfs(adj, visited, source, destination);
    }
};