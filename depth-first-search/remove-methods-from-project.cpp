class Solution {
public:
    void dfs(int i, vector<bool>& suspicious, vector<int>& indegree, vector<vector<int>>& adj) {
        suspicious[i] = true;
        for (int j : adj[i]) {
            indegree[j] -= 1;
            if (!suspicious[j]) {
                dfs(j, suspicious, indegree, adj);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // adjaceny list
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        // edges
        for (auto& e : invocations) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]] += 1;
        }
        vector<bool> suspicious(n, false);
        // dfs for suspicious
        dfs(k, suspicious, indegree, adj);
        // ans array
        bool cannotRemove = false;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (suspicious[i] && indegree[i] > 0) {
                cannotRemove = true;
                break;
            }
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }
        if (cannotRemove) {
            vector<int> res(n);
            iota(res.begin(), res.end(), 0);
            return res;
        }
        return ans;
    }
};