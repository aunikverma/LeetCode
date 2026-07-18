class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // single node tree

        // Step 1: Build adjacency list and degree array
        vector<unordered_set<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].insert(v);
            adj[v].insert(u);
            degree[u]++;
            degree[v]++;
        }

        // Step 2: Initialize leaves
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        // Step 3: Remove leaves layer by layer
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leavesCount = q.size();
            remainingNodes -= leavesCount;

            for (int i = 0; i < leavesCount; i++) {
                int leaf = q.front();
                q.pop();

                for (int neighbor : adj[leaf]) {
                    adj[neighbor].erase(leaf);
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};