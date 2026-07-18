class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        // t is exhausted either s may or not
        if (j < 0 && (i >= 0 || i < 0)) {
            return 1;
        }
        // s is exhausted t is not
        if (i < 0 && j >= 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        // if match
        if (s[i] == t[j]) {
            ans += solve(i - 1, j - 1, s, t, dp);
        }
        ans += solve(i - 1, j, s, t, dp);
        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
        return solve(i, j, s, t, dp);
    }
};