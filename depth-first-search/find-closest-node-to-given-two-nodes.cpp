class Solution {
private:
    void dijkstra(int src, vector<int>& dist,unordered_map<int, list<int>>& adj) {
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq; // dist,node
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            for (int v : adj[node]) {
                int new_d = d + 1;
                if (new_d < dist[v]) {
                    dist[v] = new_d;
                    pq.push({new_d, v});
                }
            }
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if (node1 == node2) {
            return node1; // base case
        }
        unordered_map<int, list<int>> adj;
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            adj[i];
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        dijkstra(node1, dist1, adj);
        dijkstra(node2, dist2, adj);
        int ans = -1;
        int min_d = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int max_d = max(dist1[i], dist2[i]);
                if (max_d < min_d) {
                    min_d = max_d;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
// The maximum distance from either of the two nodes to i is as small as possible.

// If multiple nodes tie, return the smallest index i.