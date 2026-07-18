class Solution {
public:
    int ans = INT_MAX;
    void dfs(int i, vector<bool>& visited,
             unordered_map<int, list<pair<int, int>>>& adj) {
        visited[i] = true;
        for (auto& j : adj[i]) {
            ans = min(ans, j.second);
            if (!visited[j.first]) {
                dfs(j.first, visited, adj);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        // adjacency list
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto& e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        // dfs
        vector<bool> visited(n + 1, false);
        dfs(1, visited, adj);
        // global ans
        return ans;
    }
};
// since 1 to n will always be connected
// start dfs 1 and return min edge weight