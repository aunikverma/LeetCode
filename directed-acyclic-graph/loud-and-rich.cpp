class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& edges, vector<int>& quiet) {
        unordered_map<int, list<int>> adj;
        int n = quiet.size();
        vector<int> indegree(n, 0); // indegree
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++; // indegree
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i : adj[node]) {
                if (quiet[ans[node]] < quiet[ans[i]]) {
                    ans[i] = ans[node];
                }
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return ans;
    }
};

// answer[u] = quietest person richer than (or equal to) u

// answer[v] = quietest person richer than (or equal to) v so far

// If answer[u] is quieter than answer[v], update answer[v].

// ✅ This ensures quietness propagates down from richer to poorer nodes.