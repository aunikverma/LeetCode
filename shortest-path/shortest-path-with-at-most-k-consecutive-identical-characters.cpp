class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // adjacency list
        unordered_map<int, list<pair<int, int>>> adj;

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        // since single src to n - 1, hence dijkstra
        // cost,node,last Char, streak
        using state = tuple<long long, int, char, int>;

        // min heap
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({0, 0, labels[0], 1});

        // dist[node][char][streak]->min_cost
        unordered_map<int, unordered_map<char, unordered_map<int, long long>>>
            dist;
        dist[0][labels[0]][1] = 0;

        while (!pq.empty()) {
            auto [cost, node, last_char, streak] = pq.top();
            pq.pop();

            if (node == n - 1) {
                return (int)cost;
            }

            for (auto& [v, w] : adj[node]) {
                char c = labels[v];
                int new_streak = (c == last_char ? streak + 1 : 1);
                if (new_streak > k) {
                    continue;
                }
                long long new_cost = cost + w;
                if (!dist[v][c].count(new_streak) ||
                    new_cost < dist[v][c][new_streak]) {
                    dist[v][c][new_streak] = new_cost;
                    pq.push({new_cost, v, c, new_streak});
                }
            }
        }
        return -1;
    }
};