class Solution {
private:
    int solve(vector<int>& days, vector<int>& costs, int ind, vector<int>& dp) {
        if (ind >= days.size()) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        // 1 - day
        int opt1 = costs[0] + solve(days, costs, ind + 1, dp);
        // 7 - day
        int j;
        for (j = ind; j < days.size() && days[j] < days[ind] + 7; j++)
            ;
        int opt2 = costs[1] + solve(days, costs, j, dp);
        // 30 - day
        for (j = ind; j < days.size() && days[j] < days[ind] + 30; j++)
            ;
        int opt3 = costs[2] + solve(days, costs, j, dp);

        return dp[ind] = min(opt1, min(opt2, opt3));
    }

    int solveTab(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            // 1 - day
            int opt1 = costs[0] + dp[i + 1];
            // 7 - day
            int j;
            for (j = i; j < days.size() && days[j] < days[i] + 7; j++)
                ;
            int opt2 = costs[1] + dp[j];
            // 30 - day
            for (j = i; j < days.size() && days[j] < days[i] + 30; j++)
                ;
            int opt3 = costs[2] + dp[j];

            dp[i] = min(opt1, min(opt2, opt3));
        }
        return dp[0];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int n = days.size();
        // vector<int> dp(n + 1, -1);
        // return solve(days, costs, 0, dp);
        // return solveTab(days, costs);

        // using queues
        queue<pair<int, int>> month;
        queue<pair<int, int>> week;
        int ans = 0;
        for (int d : days) {
            // remove expired days
            while (!month.empty() && month.front().first + 30 <= d) {
                month.pop();
            }
            while (!week.empty() && week.front().first + 7 <= d) {
                week.pop();
            }
            month.push({d, ans + costs[2]});
            week.push({d, ans + costs[1]});
            ans = min(ans + costs[0], min(month.front().second, week.front().second));
        }
        return ans;
    }
};