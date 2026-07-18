class Solution {
public:
    bool canChange(string s, string t) {
        int i = 0, j = 0;
        while (i < s.length() || j < t.length()) {
            while (i < s.length() && s[i] == '_') { // trailing underscores
                i++;
            }
            while (j < t.length() && t[j] == '_') { // trailing underscores
                j++;
            }
            if (i == s.length() || j == s.length()) {
                break; // if reached at last then break
            }
            if (s[i] != t[j]) { // if L and R
                return false;
            } else if (s[i] == 'L' && i < j) { // if L is forward
                return false;
            } else if (s[i] == 'R' && j < i) { // if R is at the back
                return false;
            }
            i++;
            j++;
        }
        return (i == s.length() && j == t.length());
    }
};