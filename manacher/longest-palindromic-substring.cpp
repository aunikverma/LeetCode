class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxlen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxlen) {
                    start = left;
                    maxlen = right - left + 1;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);       // Odd length palindrome
            expand(i, i + 1);   // Even length palindrome
        }

        return s.substr(start, maxlen);
    }
};