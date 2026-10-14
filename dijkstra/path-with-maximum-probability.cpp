class Solution {
private:
    void dijkstra(vector<double>& dist,
                  unordered_map<int, list<pair<int, double>>>& adj, int src) {
        dist[src] = 1.0;                      // prob of src 1
        priority_queue<pair<double, int>> pq; // prob src
        pq.push({1.0, src});
        while (!pq.empty()) {
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            for (auto i : adj[node]) {
                double new_p = prob * i.second;
                if (dist[i.first] < new_p) { // if greater then replace
                    dist[i.first] = new_p;
                    pq.push({new_p, i.first});
                }
            }
        }
    }

public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        unordered_map<int, list<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i]; // undirected map
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }
        vector<double> dist(n, 0.0); // start prob 0
        dijkstra(dist, adj, start_node);
        return dist[end_node]; // from src node to end node
    }
};