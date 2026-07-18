class Solution {
private:
    void dijkstra(int src,
                  unordered_map<int, vector<tuple<int, int, int>>>& adj,
                  vector<int>& dist) {
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            for (auto& [v, st, et] : adj[node]) {
                if (time <= et) {
                    int new_time = max(time, st) + 1;
                    if (new_time < dist[v]) {
                        dist[v] = new_time;
                        pq.push({new_time, v});
                    }
                }
            }
        }
    }

public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<tuple<int, int, int>>> adj;
        for (auto& e : edges) {
            int u = e[0], v = e[1], st = e[2], et = e[3];
            adj[u].emplace_back(v, st, et);
        }
        vector<int> dist(n, INT_MAX);
        dijkstra(0, adj, dist);
        return (dist[n - 1] != INT_MAX) ? dist[n - 1] : -1;
    }
};