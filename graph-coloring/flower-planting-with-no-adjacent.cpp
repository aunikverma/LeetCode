class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, list<int>> adj;
        for (auto& e : paths) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n, 0); // flower types for each garden

        for (int i = 1; i <= n; i++) {
            // Track used flower types by neighbors
            vector<bool> used(5, false); // flower types 1..4
            for (int nei : adj[i]) {
                if (ans[nei - 1] != 0) {
                    used[ans[nei - 1]] = true;
                }
            }
            // Assign the first available flower type
            for (int f = 1; f <= 4; f++) {
                if (!used[f]) {
                    ans[i - 1] = f;
                    break;
                }
            }
        }
        return ans;
    }
};
// general case
//  bool dfs(int node, unordered_map<int, list<int>>& adj, vector<int>& ans, int
//  k) {
//      if (node > ans.size()) return true; // all gardens assigned

//     for (int color = 1; color <= k; color++) {
//         bool valid = true;
//         for (int nei : adj[node]) {
//             if (ans[nei - 1] == color) {
//                 valid = false;
//                 break;
//             }
//         }
//         if (valid) {
//             ans[node - 1] = color;
//             if (dfs(node + 1, adj, ans, k)) return true;
//             ans[node - 1] = 0; // backtrack
//         }
//     }
//     return false;
// }
