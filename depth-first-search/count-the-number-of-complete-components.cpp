class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find_parent(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find_parent(parent[i]);
    }

    void union_set(int u, int v) {
        int u_parent = find_parent(u);
        int v_parent = find_parent(v);

        if (u_parent == v_parent) {
            return;
        }
        if (rank[u_parent] == rank[v_parent]) {
            rank[u_parent] += 1;
            parent[v_parent] = u_parent;
        } else if (rank[u_parent] > rank[v_parent]) {
            parent[v_parent] = u_parent;
        } else {
            parent[u_parent] = v_parent;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // adjacency list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < n; i++) {
            adj[i];
        }
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // union-set
        rank.assign(n, 0);
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);

        for (auto& e : edges) {
            union_set(e[0], e[1]);
        }
        // count connected components now
        int ans = 0;
        unordered_map<int, list<int>> map;
        for (int i = 0; i < n; i++) {
            map[find_parent(parent[i])].push_back(i);
        }
        for (auto& i : map) {
            // no of nodes
            int n = i.second.size();
            // no of edges
            int count = 0;
            for (int j : i.second) {
                count += adj[j].size();
            }
            if (count == n * (n - 1)) {
                ans += 1;
            }
        }
        return ans;
    }
};