class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, ' '));
        // rotate 90
        // 1- transpose,2- reverse
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = grid[j][i];
            }
        }
        for (auto& i : ans) {
            reverse(i.begin(), i.end());
        }
        // applying gravity
        for (int j = 0; j < m; j++) {
            int space = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (ans[i][j] == '*') {
                    space = i - 1;
                    continue;
                } else if (ans[i][j] == '#') {
                    ans[space][j] = '#';
                    if (space != i) {
                        ans[i][j] = '.';
                    }
                    space--;
                }
            }
        }
        return ans;
    }
};