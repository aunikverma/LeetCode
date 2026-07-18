class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            // base case
            return 0;
        }
        unordered_map<int, set<int>> mp;
        // num->indexes
        for (int i = 0; i < n; i++) {
            mp[arr[i]].insert(i);
        }
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = true;
        int ans = INT_MAX;
        while (!q.empty()) {
            int n1 = q.size();
            while (n1--) {
                auto [i, jumps] = q.front();
                q.pop();
                if (i == n - 1) {
                    ans = min(ans, jumps);
                }
                if (i - 1 >= 0 && arr[i] != arr[i - 1] && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push({i - 1, jumps + 1});
                    mp[arr[i]].erase(i - 1);
                }
                if (i + 1 < n && arr[i] != arr[i + 1] && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push({i + 1, jumps + 1});
                    mp[arr[i]].erase(i + 1);
                }
                for (int j : mp[arr[i]]) {
                    if (i != j && arr[i] == arr[j] && !visited[j]) {

                        visited[j] = true;
                        q.push({j, jumps + 1});
                        mp[arr[i]].erase(j);
                    }
                }
            }
        }
        return ans;
    }
};