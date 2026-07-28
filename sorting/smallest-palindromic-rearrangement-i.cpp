class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        // sort half part
        sort(s.begin(), s.begin() + (n / 2));

        // making similar
        int l = 0, r = s.length() - 1;
        while (l < r) {
            s[r] = s[l];
            l++;
            r--;
        }
        return s;
    }
};