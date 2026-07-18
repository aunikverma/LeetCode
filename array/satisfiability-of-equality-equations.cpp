class Solution {
private:
    int find_p(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find_p(parent[i], parent); // path compression
    }

    void union_set(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_p = find_p(x, parent);
        int y_p = find_p(y, parent);
        if (x_p != y_p) {
            if (rank[x_p] > rank[y_p]) {
                parent[y_p] = x_p;
            } else if (rank[y_p] > rank[x_p]) {
                parent[x_p] = y_p;
            } else {
                parent[y_p] = x_p;
                rank[x_p]++;
            }
        }
    }

public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26, 0); //since only lower case letters
        vector<int> rank(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (auto& s : equations) { //we are doing using nos
            if (s[1] == '=') {
                union_set(s[0] - 'a', s[3] - 'a', parent, rank);
            }
        }
        for (auto& s : equations) {
            if (s[1] == '!') {
                if (find_p(s[0] - 'a', parent) == find_p(s[3] - 'a', parent)) {
                    return false;
                }
            }
        }
        return true;
    }
};