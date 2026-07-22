class Solution {
public:
    int m, n;
    int solveTab(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == 1) {
                    if (i == m - 1 || j == n - 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min(dp[i + 1][j],
                                           min(dp[i][j + 1], dp[i + 1][j + 1]));
                    }
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        return solveTab(matrix);
    }
};