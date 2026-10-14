class Solution {
public:
    int dp[101][101][201];

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        if ((m + n - 1) & 1) {
            return false;
        }

        memset(dp, 0, sizeof(dp));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int bal = 0; bal <= (i + j + 1); bal++) {
                    if (i == m - 1 && j == n - 1) {
                        dp[i][j][bal] = (bal == 0);
                        continue;
                    }
                    if (i + 1 < m) {
                        int n_bal = bal + (grid[i + 1][j] == '(' ? 1 : -1);
                        if (n_bal >= 0 && dp[i + 1][j][n_bal] == true) {
                            dp[i][j][bal] = true;
                        }
                    }
                    if (j + 1 < n) {
                        int n_bal = bal + (grid[i][j + 1] == '(' ? 1 : -1);
                        if (n_bal >= 0 && dp[i][j + 1][n_bal] == true) {
                            dp[i][j][bal] = true;
                        }
                    }
                }
            }
        }
        return dp[0][0][1];
    }
};
// since if grid[0][0] == ')' we return false;
// thats why dp[0][0][1] since balance is 1 for open bracket