class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int st = 0;
        int e = s.length() - 1;
        while (st <= e) {
            if (s[st] != s[e]) {
                if (s[st] > s[e]) {
                    s[st] = s[e];
                } else {
                    s[e] = s[st];
                }
            }
            st++;e--;
        }
        return s;
    }
};