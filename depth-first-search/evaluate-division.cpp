class Solution {
private:
    bool getdist(string u, string v,
                 unordered_map<string, list<pair<string, double>>>& adj,
                 unordered_map<string, bool>& visited, double& prod) {
        if (u == v) {
            return true; // if found
        }
        visited[u] = true;
        for (auto i : adj[u]) {
            if (!visited[i.first]) {
                prod *= i.second; // not visited
                if (getdist(i.first, v, adj, visited, prod)) {
                    return true;
                }
                prod /= i.second; // backtrack
            }
        }
        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, list<pair<string, double>>> adj;
        for (int i = 0; i < values.size(); i++) {
            auto u = equations[i][0];
            auto v = equations[i][1];
            double a = values[i];             // directed edges of values
            adj[u].push_back({v, a});         // a = xb;
            adj[v].push_back({u, (1.0 / a)}); // b = a / x
        }

        vector<double> ans(queries.size(), -1.0); // declaring ans

        for (int i = 0; i < queries.size(); i++) {
            string u = queries[i][0];
            string v = queries[i][1];
            if (u == v && adj.count(u) > 0) { // if u and v are same and in adj
                ans[i] = 1.0;                 // then 1
            } else if (adj.count(u) > 0 &&
                       adj.count(v) > 0) { // if u and v are in adj
                double prod = 1.0;
                unordered_map<string, bool> visited; // find distance from u to
                                                     // v
                if (getdist(u, v, adj, visited, prod)) {
                    ans[i] = prod; // prod into ans
                }
            }
        }
        return ans;
    }
};