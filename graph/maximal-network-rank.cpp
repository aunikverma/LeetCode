class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, set<int>> adj;
        for (auto& e : roads) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = adj[i].size() + adj[j].size(); // between every set of pairs
                if (adj[i].count(j)) {
                    rank -= 1; // formula if i and j connected then minus 1
                }
                ans = max(ans, rank);
            }
        }
        return ans;
    }
};