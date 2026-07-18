class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> row_sum(m, 0);
        vector<long long> col_sum(n, 0);
        long long total_sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row_sum[i] += grid[i][j];
                col_sum[j] += grid[i][j];
                total_sum += grid[i][j];
            }
        }
        // base case
        if (total_sum % 2 != 0) {
            return false;
        }
        long long sum = 0;
        // horizontal
        for (int i = 0; i < m - 1; i++) {
            sum += row_sum[i];
            if (sum == (total_sum - sum)) {
                return true;
            }
        }
        sum = 0;
        // vertical
        for (int i = 0; i < n - 1; i++) {
            sum += col_sum[i];
            if (sum == (total_sum - sum)) {
                return true;
            }
        }
        return false;
    }
};