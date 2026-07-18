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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1; // base case
        }
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int components = n; // no of isolated components
        for (auto& e : connections) {
            int x = e[0], y = e[1];//the one with extra edge will not executed
            if(find_p(x,parent) != find_p(y,parent)) //two isolated components
            {
                union_set(x,y,parent,rank); //combine them
                components--;
            }
        }
        return (components - 1); // min edge to connect n isolated components is n - 1
    }
};