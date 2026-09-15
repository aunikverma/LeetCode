class Solution {
public:
    void fill(vector<vector<bool>>& is_palindrome, string& s) {
        // length
        // is_palindrome s[i..j]
        int n = s.length();
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                int j = i + l - 1;
                if (i == j) {
                    // single char
                    is_palindrome[i][j] = true;
                } else if (i + 1 == j) {
                    // double char
                    is_palindrome[i][j] = (s[i] == s[j]);
                } else {
                    // more than 2
                    is_palindrome[i][j] =
                        ((s[i] == s[j]) && is_palindrome[i + 1][j - 1]);
                }
            }
        }
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        // base case
        if (k == 1) {
            return n;
        }
        vector<vector<bool>> is_palindrome(n + 1, vector<bool>(n + 1, false));
        // filling is_palindrome
        fill(is_palindrome, s);
        // dp array
        vector<int> dp(n + 1, 0);
        for (int l = k; l <= n; l++) {
            int j = l - 1;
            // skip j th char
            int ans = dp[j];
            for (int i = 0; j - i + 1 >= k; i++) {
                if (is_palindrome[i][j]) {
                    // since is_palindrome[i..j] check left of i
                    ans = max(ans, 1 + dp[i]);
                }
            }
            dp[l] = ans;
        }
        return dp[n];
    }
};