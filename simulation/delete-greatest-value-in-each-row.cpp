class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) sort(grid[i].begin(), grid[i].end());
        int ans = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            int a = INT_MIN;
            for (int i = 0; i < grid.size(); i++) {
                a = max(a, grid[i][j]);
            }
            ans += a;
        }
        return ans;
    }
};