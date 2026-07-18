class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        for (int j = 0; j < grid[0].size(); j++) {
            int a = INT_MIN;
            for (int i = 0; i < grid.size(); i++) {
                string s = to_string(grid[i][j]);
                int x = s.length();
                a = max(a, x);
            }
            ans.push_back(a);
        }
        return ans;
    }
};