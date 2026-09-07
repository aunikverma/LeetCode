class Solution {
public:
    int Mod = 1e9 + 7;
    int n;
    int solve(int i, int prev, string& s, vector<vector<int>>& dp) {
        if (i >= n) {
            return 0;
        }
        if (prev != -1 && dp[i][prev] != -1) {
            return dp[i][prev];
        }
        int ans = 0;
        // if same as prev move forward
        if (prev != -1 && s[i] == s[prev]) {
            ans = (ans + solve(i + 1, prev, s, dp)) % Mod;
        } else {
            // if not either take it or not take it
            ans = (ans + solve(i + 1, prev, s, dp)) % Mod;
            ans = (ans + 1 + solve(i + 1, i, s, dp)) % Mod;
        }
        if (prev != -1) {
            dp[i][prev] = ans;
        }
        return ans;
    }

    int distinctSubseqII(string s) {
        n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, -1, s, dp);
    }
};