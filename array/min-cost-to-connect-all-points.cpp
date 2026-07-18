class Solution {
public:
    typedef pair<int, int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, list<P>> adj;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        int ans = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<bool> visited(n, false);
        while (!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();
            if (visited[node]) {
                continue;
            }
            ans += w;
            visited[node] = true;
            for (auto& i : adj[node]) {
                if (!visited[i.first]) {
                    pq.push({i.second, i.first});
                }
            }
        }
        return ans;
    }
};