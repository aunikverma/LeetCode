class Solution {
public:
    int m, n;
    typedef long long ll;
    int mod = 1e9 + 7;
    vector<vector<pair<ll, ll>>> dp;

    // pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
    //     if (i == m - 1 && j == n - 1) {
    //         return {grid[i][j], grid[i][j]};
    //     }
    //     ll max_val = LLONG_MIN;
    //     ll min_val = LLONG_MAX;

    //     if (dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
    //         return dp[i][j];
    //     }

    //     // down
    //     if (i + 1 < m) {
    //         auto [down_max, down_min] = solve(i + 1, j, grid);
    //         max_val =
    //             max({max_val, grid[i][j] * down_max, grid[i][j] * down_min});
    //         min_val =
    //             min({min_val, grid[i][j] * down_max, grid[i][j] * down_min});
    //     }

    //     // right
    //     if (j + 1 < n) {
    //         auto [right_max, right_min] = solve(i, j + 1, grid);
    //         max_val =
    //             max({max_val, grid[i][j] * right_max, grid[i][j] *
    //             right_min});
    //         min_val =
    //             min({min_val, grid[i][j] * right_max, grid[i][j] *
    //             right_min});
    //     }

    //     return dp[i][j] = {max_val, min_val};
    // }

    int solveTab(vector<vector<int>>& grid) {
        dp = vector<vector<pair<ll, ll>>>(
            m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        dp[m - 1][n - 1] = make_pair(grid[m - 1][n - 1], grid[m - 1][n - 1]);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                ll max_val = LLONG_MIN;
                ll min_val = LLONG_MAX;
                // down
                if (i + 1 < m) {
                    auto [down_max, down_min] = dp[i + 1][j];
                    max_val = max({max_val, grid[i][j] * down_max,
                                   grid[i][j] * down_min});
                    min_val = min({min_val, grid[i][j] * down_max,
                                   grid[i][j] * down_min});
                }

                // right
                if (j + 1 < n) {
                    auto [right_max, right_min] = dp[i][j + 1];
                    max_val = max({max_val, grid[i][j] * right_max,
                                   grid[i][j] * right_min});
                    min_val = min({min_val, grid[i][j] * right_max,
                                   grid[i][j] * right_min});
                }
                dp[i][j] = {max_val, min_val};
            }
        }
        auto [maxi_prod, mini_prod] = dp[0][0];
        return (maxi_prod < 0 ? -1 : maxi_prod % mod);
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        // dp = vector<vector<pair<ll, ll>>>(
        //     m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        // auto [maxi_prod, mini_prod] = solve(0, 0, grid);
        // return (maxi_prod < 0 ? -1 : maxi_prod % mod);
        return solveTab(grid);
    }
};