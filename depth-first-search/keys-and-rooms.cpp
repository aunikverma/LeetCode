class Solution {
private:
    void dfs(int s, unordered_map<int, list<int>>& adj, vector<bool>& visited) {
        visited[s] = true;
        for (int i : adj[s]) {
            if (!visited[i]) {
                dfs(i, adj, visited);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < rooms.size(); i++) {
            int u = i;
            for (int v : rooms[i]) {
                adj[u].push_back(v); // directed graph
            }
        }
        vector<bool> visited(rooms.size(), false); // visited map
        dfs(0, adj, visited);                      // visiting using dfs
        for (auto i : visited) {
            if (i == false) { // if any room false or not visited
                return false; // return false
            }
        }
        return true;
    }
};