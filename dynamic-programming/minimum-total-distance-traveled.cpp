class Solution {
public:

    typedef long long ll;

    ll solve(int i, int j, vector<int>& robot, vector<int>& positions, vector<vector<ll>>& dp) {
        if (i >= robot.size()) {
            return 0;
        }
        if (j >= positions.size()) {
            return (1e12);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        ll take = abs(robot[i] - positions[j]) + solve(i + 1, j + 1, robot, positions, dp);
        ll skip = solve(i, j + 1, robot, positions, dp);
        return dp[i][j] = min(take, skip);
    }

    ll solveTab(vector<int>& robot,vector<int>& positions) {
        int m = robot.size(),n = positions.size();
        vector<vector<ll>>dp(m + 1,vector<ll>(n + 1,0));
        //base case
        for(int i = 0;i < m;i++){
            dp[i][n] = 1e12;
        }

        for(int i = m - 1;i >= 0;i--) {
            for(int j = n - 1;j >= 0;j--) {
                ll take = abs(robot[i] - positions[j]) + dp[i + 1][j + 1];
                ll skip = dp[i][j + 1];
                dp[i][j] = min(take, skip);
            }
        }
        return dp[0][0];
    }

    ll solveTabSpace(vector<int>& robot,vector<int>& positions) {
        int m = robot.size(),n = positions.size();
        vector<ll>curr(n + 1,0);
        vector<ll>next(n + 1,0);
        //base case
        curr[n] = 1e12;

        for(int i = m - 1;i >= 0;i--) {
            for(int j = n - 1;j >= 0;j--) {
                ll take = abs(robot[i] - positions[j]) + next[j + 1];
                ll skip = curr[j + 1];
                curr[j] = min(take, skip);
            }
            next = curr;
        }
        return curr[0];
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // step-1
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        // step-2
        vector<int> positions;
        for (int i = 0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos = factory[i][0];
            for (int j = 0; j < limit; j++) {
                positions.push_back(pos);
            }
        }
        // step-3
        // vector<vector<ll>>dp(robot.size() + 1,vector<ll>(positions.size() + 1,-1));
        // return solve(0, 0, robot, positions, dp);

        //step - 4
        // return solveTab(robot,positions);

        //step - 5
        return solveTabSpace(robot,positions);
    }
};