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
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (is_palindrome[i][j]) {
                    int take = 1 + (j + k <= n ? dp[j + 1][j + k] : 0);
                    int grow = dp[i][j + 1];
                    int slide = dp[i + 1][j + 1];
                    dp[i][j] = max({take, grow, slide});
                }
                int grow = dp[i][j + 1];
                int slide = dp[i + 1][j + 1];
                dp[i][j] = max({dp[i][j], grow, slide});
            }
        }
        return dp[0][k - 1];
    }
};