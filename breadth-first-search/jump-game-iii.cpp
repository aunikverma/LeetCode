class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if (arr[start] == 0) {
            return true;
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int n1 = q.size();
            while (n1--) {
                int i = q.front();
                q.pop();
                if (arr[i] == 0) {
                    return true;
                }
                if ((i + arr[i]) < n && !visited[i + arr[i]]) {
                    q.push(i + arr[i]);
                    visited[i + arr[i]] = true;
                }
                if ((i - arr[i]) >= 0 && !visited[i - arr[i]]) {
                    q.push(i - arr[i]);
                    visited[i - arr[i]] = true;
                }
            }
        }
        return false;
    }
};