class Solution {
private:
    int solve(unordered_map<int, list<pair<int, int>>>& adj, int n, int src,
              int dst, int k) {
        typedef pair<int, pair<int, int>> PP; // {cost, {node, stops}}
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({0, {src, 0}});

        // Track cost to reach each node with a given number of stops
        vector<vector<int>> cost(
            n, vector<int>(k + 2,
                           INT_MAX)); // k + 2 because path include two nodes
        cost[src][0] = 0;             // stops 0 ,cost 0

        while (!pq.empty()) {
            PP curr = pq.top();
            int price = curr.first;
            int node = curr.second.first;
            int stops = curr.second.second;
            pq.pop();

            if (node == dst)
                return price;
            if (stops > k)
                continue;

            for (auto& [i, p] : adj[node]) { // dijkstra logic
                int new_p = p + price;
                if (new_p < cost[i][stops + 1]) {
                    cost[i][stops + 1] = new_p;
                    pq.push({new_p, {i, stops + 1}});
                }
            }
        }
        return -1;
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto& f : flights) {
            int u = f[0];
            int v = f[1];
            int p = f[2];             // price
            adj[u].push_back({v, p}); // directed
        }
        return solve(adj, n, src, dst, k);
    }
};