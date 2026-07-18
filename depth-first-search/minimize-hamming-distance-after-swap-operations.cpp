class Solution {
public:
    int find_parent(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find_parent(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find_parent(x, parent);
        int y_parent = find_parent(y, parent);
        if (x_parent == y_parent) {
            return;
        }
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        vector<int> rank(n, 0);
        for (auto& e : allowedSwaps) {
            Union(e[0], e[1], parent, rank);
        }

        // component and index
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[find_parent(i, parent)].push_back(i);
        }
        // count mismatches
        int count = 0;
        for (auto& [root, indexes] : mp) {
            unordered_map<int, int> freq;
            for (int i : indexes) {
                freq[source[i]]++;
            }
            for (int i : indexes) {
                if (freq[target[i]] > 0) {
                    freq[target[i]]--;
                } else {
                    count++;
                }
            }
        }
        return count;
    }
};