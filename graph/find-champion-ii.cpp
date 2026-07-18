class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            indegree[v]++;
        }
        int count = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) { // hint indegree of champion should be zero
                count++;
                ans = i;
            }
        }
        return (count == 1) ? ans : -1; // if only one champion
    }
};