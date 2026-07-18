class Solution {
private:
    int find_p(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find_p(parent[i], parent);
    }
    void union_set(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_p = find_p(x, parent);
        int y_p = find_p(y, parent);
        if (rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;
        } else if (rank[y_p] > rank[x_p]) {
            parent[x_p] = y_p;
        } else {
            parent[y_p] = x_p;
            rank[x_p]++;
        }
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto& e : edges) {
            if (find_p(e[0], parent) != find_p(e[1], parent)) {
                union_set(e[0], e[1], parent, rank);
            }
        }
        unordered_map<int, int> mp; // size of components
        for (int i = 0; i < n; i++) {
            mp[find_p(i, parent)]++;
        }
        long long remaining = n; // at start
        long long ans = 0;
        for (auto& v : mp) {
            ans += v.second * (remaining - v.second);
            remaining -= v.second;
        }
        return ans;
    }
};