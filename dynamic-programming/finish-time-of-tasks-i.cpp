class Solution {
public:

    typedef long long ll;
    
    ll dfs(int i, unordered_map<int, list<int>>& adj, vector<int>& baseTime) {
        // if leaf node
        if (adj[i].empty()) {
            return (ll) baseTime[i];
        }

        ll latest = LLONG_MIN, earliest = LLONG_MAX;

        for (int j : adj[i]) {
            ll  duration = dfs(j, adj, baseTime);
            latest = max(latest, duration);
            earliest = min(earliest, duration);
        }
        ll own_duration = baseTime[i] + (latest - earliest);
        return (latest + own_duration);
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        // adjacency list
        unordered_map<int, list<int>> adj;
        for (auto& e : edges) {
            // since undirected
            adj[e[0]].push_back(e[1]);
        }

        // finish time of zero
        ll ans = dfs(0, adj, baseTime);
        return ans;
    }
};