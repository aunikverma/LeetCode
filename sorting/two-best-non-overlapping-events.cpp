class Solution {
private:
    // first event whose starting time is greater than my event
    int bin(vector<vector<int>>& events, int end_time) {
        int l = 0, r = events.size() - 1, ans = events.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] > end_time) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& events, int ind, int count,
              vector<vector<int>>& dp) {
        if (count == 2 || ind >= events.size()) {
            return 0; // max 2 event
        }
        if (dp[ind][count] != -1) {
            return dp[ind][count];
        }
        int next_valid_ind = bin(events, events[ind][1]);
        int take =
            events[ind][2] + solve(events, next_valid_ind, count + 1, dp);
        int not_take = solve(events, ind + 1, count, dp);
        return dp[ind][count] = max(take, not_take);
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(100001, vector<int>(3, -1));
        int count = 0;
        return solve(events, 0, count, dp);
    }
};