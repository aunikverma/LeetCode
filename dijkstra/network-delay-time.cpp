class Solution {
private:
    typedef pair<int, int> PP;
    int solve(unordered_map<int, list<pair<int, int>>>& adj, int& n, int& src) {
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({0, src}); // wt,node
        while (!pq.empty()) {
            PP curr = pq.top();
            pq.pop();
            int node = curr.second;
            int wt = curr.first;
            for (auto i : adj[node]) {
                if (i.second + wt < dist[i.first]) {
                    dist[i.first] = i.second + wt;
                    pq.push({i.second + wt, i.first});
                }
            }
        }
        int maxi = INT_MIN; // finding all distance from source node to all
                            // nodes
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1; // if any node is unreachable
            } else {
                maxi = max(maxi, dist[i]); // else max time to reach all nodes
            }
        }
        return maxi;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int, int>>> adj; // node : {node : time}
        for (auto t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].push_back({v, w}); // directed edge
        }
        return solve(adj, n, k);
    }
};