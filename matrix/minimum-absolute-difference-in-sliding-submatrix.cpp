class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                set<int> val;
                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        val.insert(grid[r][c]);
                    }
                }
                if (val.size() == 1) {
                    continue;
                }
                int min_diff = INT_MAX;
                auto prev = val.begin();
                auto curr = next(prev);
                while (curr != val.end()) {
                    min_diff = min(min_diff, *curr - *prev);
                    prev = curr;
                    curr++;
                }
                ans[i][j] = min_diff;
            }
        }
        return ans;
    }
};