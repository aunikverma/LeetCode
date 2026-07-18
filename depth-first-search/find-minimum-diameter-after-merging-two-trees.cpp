class Solution {
private:
    pair<int, int> bfs(unordered_map<int, list<int>>& adj, int src) {
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        int farthest = src;
        int dist = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n) {
                int curr = q.front();
                q.pop();
                farthest = curr;
                for (auto& i : adj[curr]) {
                    if (!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
                n--;
            }
            if (!q.empty()) {
                dist++;
            }
        }
        return {farthest, dist};
    }
    int diameter(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // step 1 farthest node from random node
        auto [farthest_node, dist] = bfs(adj, 0);
        // find the farthest node from the farthest_node from above
        auto [other_end, dia] = bfs(adj, farthest_node);
        return dia;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,vector<vector<int>>& edges2) {
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);
        int d_merge = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;
        return max(d1, max(d2, d_merge));
    }
};