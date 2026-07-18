class Solution {
private:
    void dfs(int i, unordered_map<int, list<int>>& adj,
             unordered_map<int, bool>& visited) {
        visited[i] = true;
        for (auto& j : adj[i]) {
            if (!visited[j]) {
                dfs(j, adj, visited);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, list<int>> adj;
        // since two stones are connected if they share same row or col
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0; // no of connected components
        unordered_map<int, bool> visited;
        for (auto& i : adj) {
            if (!visited[i.first]) {
                count++;
                dfs(i.first, adj, visited);
            }
        }
        return (n - count);
    }
};