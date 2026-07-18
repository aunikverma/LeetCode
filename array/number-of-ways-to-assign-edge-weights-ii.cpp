class Solution {
public:
    typedef long long ll;
    int Mod = 1e9 + 7;
    int cols;
    vector<int> depth;
    vector<vector<int>> parent_map;

    // power
    ll power(ll base, ll exp) {
        if (exp == 0) {
            return 1;
        }
        ll half = power(base, exp / 2);
        ll ans = (half * half) % Mod;
        if (exp & 1) {
            ans = (ans * base) % Mod;
        }
        return ans;
    }

    // lca using binary lifting
    int lca(int u, int v) {
        // ensure u is deeper
        if (depth[v] > depth[u]) {
            swap(u, v);
        }
        // lift u upto same level as v
        int diff = depth[u] - depth[v];
        for (int j = 0; j < cols; j++) {
            if (diff & (1 << j)) {
                u = parent_map[u][j];
            }
        }
        // if equal after lifting
        if (u == v) {
            return u;
        }
        // lift both until same parent
        for (int j = cols - 1; j >= 0; j--) {
            if (parent_map[u][j] != -1 &&
                parent_map[u][j] != parent_map[v][j]) {
                u = parent_map[u][j];
                v = parent_map[v][j];
            }
        }
        // return immediate parent
        return parent_map[u][0];
    }

    // get_distance
    int get_distance(int u, int v) {
        return (depth[u] + depth[v] - 2 * depth[lca(u, v)]);
    }

    // dfs
    void dfs(int node, int parent, unordered_map<int, list<int>>& adj, vector<bool>& visited) {
        parent_map[node][0] = parent;
        visited[node] = true;

        for (int j : adj[node]) {
            if (!visited[j]) {
                depth[j] = 1 + depth[node];
                dfs(j, node, adj, visited);
            }
        }
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // adjacency list
        unordered_map<int, list<int>> adj;
        for (auto& q : edges) {
            int u = q[0], v = q[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // no of nodes
        int n = adj.size();

        // depth and visited
        depth.assign(n + 1, 0);
        vector<bool> visited(n + 1, false);

        // assign parent_mapping
        cols = log2(n) + 1;
        parent_map.assign(n + 1, vector<int>(cols, -1));

        // dfs to fill depth and parent_map[node][0]
        dfs(1, -1, adj, visited);

        // filling rest of parent_map table
        for (int j = 1; j < cols; j++) {
            for (int i = 1; i <= n; i++) {
                if (parent_map[i][j - 1] != -1) {
                    parent_map[i][j] = parent_map[parent_map[i][j - 1]][j - 1];
                }
            }
        }

        // result vector
        vector<int> ans;

        // processing queries
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
            } else {
                int distance = get_distance(u, v);
                int ways = power(2, distance - 1);
                ans.push_back(ways);
            }
        }
        return ans;
    }
};