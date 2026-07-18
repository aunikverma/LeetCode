class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int m = INT_MIN;
        int ans = -1; // index of row to return
        for (int i = 0; i < grid.size(); i++) {
            int s = 0;
            for (int j = 0; j < grid[0].size(); j++) {
                s += grid[i][j];
            }
            if (s > m) {
                m = s;
                ans = i;
            }
        }
        return ans;
    }
};