class Solution {
public:
    double dfs(int node, unordered_map<int, list<int>>& adj, int& target,
               int time, vector<bool>& visited, int& dest_time, double prob) {
        visited[node] = true;
        if (time > dest_time) {
            return 0.0;
        }
        if (time == dest_time) {
            return (node == target ? prob : 0.0);
        }
        int unvisited = 0;
        for (int i : adj[node]) {
            if (!visited[i]) {
                unvisited++;
            }
        }
        if (unvisited == 0) {
            return (node == target ? prob : 0.0);
        }
        double ans = 0;
        for (int i : adj[node]) {
            if (!visited[i]) {
                ans += dfs(i, adj, target, time + 1, visited, dest_time,
                           (prob / unvisited));
            }
        }
        return ans;
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, list<int>> adj;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n + 1, false);
        return dfs(1, adj, target, 0, visited, t, 1);
    }
};