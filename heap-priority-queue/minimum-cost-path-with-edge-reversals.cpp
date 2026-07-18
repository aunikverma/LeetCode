class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        // dijkstra
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0}); // dist - node
        while (!pq.empty()) {
            auto [d, node] = pq.top(); // dist - node
            pq.pop();
            if (node == n - 1) {
                return dist[n - 1];
            }
            for (auto i : adj[node]) {
                auto [neig, dt] = i; // adjacent node-dist
                if (d + dt < dist[neig]) {
                    dist[neig] = d + dt;
                    pq.push({d + dt, neig});
                }
            }
        }
        return -1;
    }
};