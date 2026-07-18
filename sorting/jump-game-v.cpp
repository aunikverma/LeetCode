class Solution {
public:
    int n;

    int solve(int i, vector<int>& arr, int d, vector<int>& dp) {
        int max_jumps = 0;
        if (dp[i] != -1) {
            return dp[i];
        }
        // jumps i can take
        for (int x = 1; x <= d; x++) {
            if (i - x >= 0 && arr[i - x] < arr[i]) {
                max_jumps = max(max_jumps, 1 + solve(i - x, arr, d, dp));
            } else {
                break;
            }
        }
        for (int x = 1; x <= d; x++) {
            if (i + x < n && arr[i + x] < arr[i]) {
                max_jumps = max(max_jumps, 1 + solve(i + x, arr, d, dp));
            } else {
                break;
            }
        }
        return dp[i] = max_jumps;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        int ans = INT_MIN;
        // sorting to find ans of that indexes which have smaller values
        // can contain duplicate values
        vector<pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            mp.push_back({arr[i], i});
        }
        sort(mp.begin(), mp.end());
        // max jumps i can take from index x
        vector<int> dp(n + 1, -1);
        for (int i = 0; i < n; i++) {
            ans = max(ans, 1 + solve(mp[i].second, arr, d, dp));
        }
        return ans;
    }
};