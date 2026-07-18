class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int, list<int>> adj;
        vector<int> indeg(n, 0);
        for (auto& e : p) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            indeg[u]++; // indegree
        }
        queue<int> q; // bfs using kahn
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int i : adj[node]) {
                indeg[i]--;
                if (indeg[i] == 0) {
                    q.push(i);
                }
            }
        }
        return (count == n);
    }
};