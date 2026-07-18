class Solution {
private:
    int find_p(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find_p(parent[i], parent);
    }
    void combine(int x, int y, vector<int>& parent, vector<int>& rank) {
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
    vector<int> processQueries(int c, vector<vector<int>>& edges,vector<vector<int>>& q) {
        vector<int> parent(c + 1, 0);
        vector<int> rank(c + 1, 0);
        vector<bool> operational(c + 1, true);
        for (int i = 1; i <= c; i++) {
            parent[i] = i;
        }
        for (auto& e : edges) {
            combine(e[0], e[1], parent, rank);
        }
        // Map from component root to set of operational nodes
        unordered_map<int, set<int>> component_operational;
        for (int i = 1; i <= c; i++) {
            int root = find_p(i, parent);
            component_operational[root].insert(i);
        }
        vector<int> ans;
        for (auto& i : q) {
            int t = i[0];
            int x = i[1];
            if (t == 2) {
                if (operational[x]) {
                    operational[x] = false;
                    int root = find_p(x, parent);
                    component_operational[root].erase(x);
                }
            } else if (t == 1) {
                if (operational[x]) {
                    ans.push_back(x);
                } else {
                    int root = find_p(x, parent);
                    if (component_operational[root].empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(*component_operational[root].begin());
                    }
                }
            }
        }
        return ans;
    }
};