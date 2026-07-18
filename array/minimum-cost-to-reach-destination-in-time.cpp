class Solution {
public:
    typedef tuple<int, int, int> State; // cost, time, node

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size(); //no of vertices
        unordered_map<int, list<pair<int, int>>> adj;

        for (auto& e : edges) { //t : time,u,v : vertices
            int u = e[0], v = e[1], t = e[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INT_MAX));
        priority_queue<State, vector<State>, greater<State>> pq;

        dp[0][0] = passingFees[0];
        pq.push({passingFees[0], 0, 0}); // cost, time, node

        while (!pq.empty()) {
            auto [cost, time, node] = pq.top();
            pq.pop();

            if (node == n - 1) return cost; //reached destination

            for (auto& [nei, t] : adj[node]) {
                int newTime = time + t;
                if (newTime > maxTime) continue;

                int newCost = cost + passingFees[nei];
                if (newCost < dp[nei][newTime]) {
                    dp[nei][newTime] = newCost;
                    pq.push({newCost, newTime, nei});
                }
            }
        }

        return -1;
    }
};