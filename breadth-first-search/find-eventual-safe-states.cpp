class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> out_deg(n, 0);
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < n; i++) {
            int u = i;
            out_deg[u] = graph[i].size();
            for (int j : graph[i]) {
                adj[j].push_back(i);
            }
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (out_deg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            ans.push_back(n);
            for (int j : adj[n]) {
                out_deg[j]--;
                if (out_deg[j] == 0) {
                    q.push(j);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};