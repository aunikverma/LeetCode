class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n, 0); // indegree
        for (auto& e : p) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u); // according to ques
            indegree[u]++;       // indegree
        }
        queue<int> q; // using bfs kahn
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i); // indegree 0
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int j : adj[node]) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    q.push(j);
                }
            }
        }
        if (ans.size() == n) {
            return ans;
        }
        return {}; // empty array
    }
};