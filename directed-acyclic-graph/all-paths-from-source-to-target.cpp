class Solution {
private:
    void dfs(int s, int t, vector<vector<int>>& graph, vector<bool>& visited,
             vector<int>& path, vector<vector<int>>& ans) {
        if (s == t) {
            ans.push_back(path);
            return;
        }
        visited[s] = true;
        for (int j : graph[s]) {
            if (!visited[j]) {
                path.push_back(j);
                dfs(j, t, graph, visited, path, ans);
                path.pop_back();
            }
        }
        visited[s] = false; // backtrack
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans; // ans
        vector<int> path = {0};  // path start 0
        vector<bool> visited(n, false);
        dfs(0, n - 1, graph, visited, path, ans);
        return ans;
    }
};