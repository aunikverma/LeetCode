class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<int, int>>> CumSum(
            m, vector<pair<int, int>>(n, {0, 0}));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x_count = 0, y_count = 0;
                if (grid[i][j] == 'X') {
                    x_count++;
                }
                if (grid[i][j] == 'Y') {
                    y_count++;
                }
                if (i > 0) {
                    x_count += CumSum[i - 1][j].first;
                    y_count += CumSum[i - 1][j].second;
                }
                if (j > 0) {
                    x_count += CumSum[i][j - 1].first;
                    y_count += CumSum[i][j - 1].second;
                }
                if (i > 0 && j > 0) {
                    x_count -= CumSum[i - 1][j - 1].first;
                    y_count -= CumSum[i - 1][j - 1].second;
                }
                if (x_count == y_count && x_count > 0) {
                    count++;
                }
                CumSum[i][j].first = x_count;
                CumSum[i][j].second = y_count;
            }
        }
        return count;
    }
};