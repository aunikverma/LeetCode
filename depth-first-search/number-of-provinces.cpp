class Solution {
private:
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& isConnected) {
        visited[i] = true;
        for (int j = 0; j < isConnected[i].size(); j++) {
            if (!visited[j] && isConnected[i][j] == 1) {
                dfs(j, visited, isConnected);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, visited, isConnected);
            }
        }
        return components;
    }
};