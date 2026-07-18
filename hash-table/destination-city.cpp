class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, list<string>> adj;
        for (auto& e : paths) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]];
        }
        for (auto& i : adj) {
            if (i.second.empty()) {
                return i.first;
            }
        }
        return "";
    }
};