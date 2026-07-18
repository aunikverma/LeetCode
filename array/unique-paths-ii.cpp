class Solution {
public:
    int m, n;

    int solve(int i, int j, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = (j + 1 < n && obstacleGrid[i][j + 1] != 1 ? solve(i,j + 1,obstacleGrid,dp) : 0);
        int down = (i + 1 < m && obstacleGrid[i + 1][j] != 1 ? solve(i + 1,j,obstacleGrid,dp) : 0);
        return dp[i][j] = (right + down);
    }

    int solveTab(vector<vector<int>>& obstacleGrid){
        vector<vector<long long>>dp(m,vector<long long>(n,0));
        //base case
        dp[m - 1][n - 1] = 1;
        for(int i = m - 1;i >= 0;i--){
            for(int j = n - 1;j >= 0;j--){
                if(i == m - 1 && j == n - 1){
                    continue;
                }
                long long right = (j + 1 < n && obstacleGrid[i][j + 1] != 1 ? dp[i][j + 1] : 0);
                long long down = (i + 1 < m && obstacleGrid[i + 1][j] != 1 ? dp[i + 1][j] : 0);
                dp[i][j] = (right + down);
            }
        }
        return (int)dp[0][0];
    }

    int solveTabSpace(vector<vector<int>>& obstacleGrid){
        vector<long long>curr(n, 0);
        vector<long long>next(n, 0);
        //base case
        curr[n - 1] = next[n - 1] = 1;
        for(int i = m - 1;i >= 0;i--){
            for(int j = n - 1;j >= 0;j--){
                if(i == m - 1 && j == n - 1){
                    continue;
                }
                long long right = (j + 1 < n && obstacleGrid[i][j + 1] != 1 ? curr[j + 1] : 0);
                long long down = (i + 1 < m && obstacleGrid[i + 1][j] != 1 ? next[j] : 0);
                curr[j] = (right + down);
            }
            next = curr;
        }
        return (int)curr[0];
    }

    

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1){
            return 0;
        }
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solve(0, 0, obstacleGrid,dp);
        // return solveTab(obstacleGrid);
        return solveTabSpace(obstacleGrid);
    }
};