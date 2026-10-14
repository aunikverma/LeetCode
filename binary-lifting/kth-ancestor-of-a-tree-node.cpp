class TreeAncestor {
public:
    vector<vector<int>> parent_map;
    int rows, cols;

    TreeAncestor(int n, vector<int>& parent) {
        rows = n;
        cols = log2(n) + 1;
        parent_map.assign(rows, vector<int>(cols, -1));
        // filling zeroth column
        for (int i = 0; i < n; i++) {
            parent_map[i][0] = parent[i];
        }
        // filling rest of table
        for (int j = 1; j < cols; j++) {
            for (int i = 0; i < n; i++) {
                if (parent_map[i][j - 1] != -1) {
                    parent_map[i][j] = parent_map[parent_map[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < cols; j++) {
            // if k jth bit is 1 then we can jump 2^j
            if (k & (1 << j)) {
                node = parent_map[node][j];
                // kth ancestor not present
                if (node == -1) {
                    return -1;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */