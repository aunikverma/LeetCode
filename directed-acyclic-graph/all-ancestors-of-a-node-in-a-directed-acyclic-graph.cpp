class Solution {
private:
    void dfs(int src, vector<int>& a, unordered_map<int, list<int>>& adj,vector<bool>& visited) {
        visited[src] = true;
        if (adj[src].empty()) {
            return; //if parent empty
        }
        for (auto& i : adj[src]) {
            if (!visited[i]) { //otherwise add in a 
                a.push_back(i);
                dfs(i, a, adj, visited);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        unordered_map<int, list<int>> adj;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u];
            adj[v].push_back(u); // reversing
        }
        for (int i = 0; i < n; i++) {
            vector<int> a;
            vector<bool> visited(n, false);
            dfs(i, a, adj, visited); //parents
            sort(a.begin(), a.end());
            ans.push_back(a);
        }
        return ans;
    }
};