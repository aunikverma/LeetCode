class Solution {
public:
    int find_parent(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find_parent(parent[i], parent);
    }

    void union_set(int u, int v, vector<int>& parent) {
        int a = find_parent(u, parent);
        int b = find_parent(v, parent);
        // not rank just make same
        if (a != b) {
            parent[a] = b;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        // parent array
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n - 1; i++) {
            if (abs(nums[i + 1] - nums[i]) <= maxDiff) {
                union_set(i, i + 1, parent);
            }
        }

        int q = queries.size();
        vector<bool> result(q, false);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0], v = queries[i][1];
            if (find_parent(u, parent) == find_parent(v, parent)) {
                result[i] = true;
            }
        }
        return result;
    }
};