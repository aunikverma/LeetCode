class Solution {
public:
    int Mod = 1e9 + 7;

    int dfs(int i, unordered_map<int, list<int>>& adj, vector<int>& visited) {
        visited[i] = true;
        int max_depth = 0;
        for (auto j : adj[i]) {
            if (!visited[j]) {
                max_depth = max(max_depth, 1 + dfs(j, adj, visited));
            }
        }
        return max_depth;
    }

    long long power(long long base, long long exp) {
        if (exp == 0) {
            return 1;
        }
        long long half = power(base, exp / 2);
        long long ans = (half * half) % Mod;
        if (exp % 2 == 1) {
            ans = (ans * base) % Mod;
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int n = adj.size();
        vector<int> visited(n + 1, false);
        int max_depth = dfs(1, adj, visited);
        return (int)power(2, max_depth - 1);
    }
};
// since we can assign edges weight 1 or 2
// for each edge we have two choices either (1 or 2)
// odd possiblity = even possibility
// therefore odd = (odd + even) / 2
// hence 2^(max_depth) / 2
// 2^(max_Depth - 1)