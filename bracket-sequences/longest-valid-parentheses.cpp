class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int open = 0, close = 0;
        int ans = 0;
        // left to right(expecting close)
        for (int i = 0; i < n; i++) {
            open += (s[i] == '(' ? 1 : 0);
            close += (s[i] == ')' ? 1 : 0);
            if (open == close) {
                ans = max(ans, open + close);
            } else if (close > open) {
                open = close = 0;
            }
        }
        // right to left(expecting open)
        open = close = 0;
        for (int i = n - 1; i >= 0; i--) {
            open += (s[i] == '(' ? 1 : 0);
            close += (s[i] == ')' ? 1 : 0);
            if (open == close) {
                ans = max(ans, open + close);
            } else if (open > close) {
                open = close = 0;
            }
        }
        return ans;
    }
};
