class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        // count length
        while (i >= 0 && s[i] != ' ') {
            i--;c++;
        }
        return c;
    }
};