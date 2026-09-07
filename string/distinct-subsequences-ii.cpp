class Solution {
public:
    int distinctSubseqII(string s) {
        int Mod = 1e9 + 7;
        int n = s.length();
        vector<int> dp(n + 1, 0);
        // empty subsequence
        dp[0] = 1;
        unordered_map<char, int> mp;
        for (int i = 1; i <= n; i++) {
            char ch = s[i - 1];
            // either take or not(2 choices)
            dp[i] = (2 * dp[i - 1]) % Mod;
            if (mp.count(ch)) {
                int last_ind = mp[ch];
                dp[i] = (dp[i] - dp[last_ind - 1] + Mod) % Mod;
            }
            // push into map
            mp[ch] = i;
        }
        // exclude empty one
        dp[n] = (dp[n] - 1 + Mod) % Mod;
        return dp[n];
    }
};