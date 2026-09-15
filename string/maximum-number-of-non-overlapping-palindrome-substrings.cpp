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

    int solve(int n, int& k, vector<int>& dp, vector<vector<bool>>& is_palindrome) {
        if (n < k) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int j = n - 1;
        // skip j th char
        int ans = solve(j, k, dp, is_palindrome);
        for (int i = 0; j - i + 1 >= k; i++) {
            if (is_palindrome[i][j]) {
                // since is_palindrome[i..j] check left of i
                ans = max(ans, 1 + solve(i, k, dp, is_palindrome));
            }
        }
        return dp[n] = ans;
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
        vector<int> dp(n + 1, -1);
        return solve(n, k, dp, is_palindrome);
    }
};