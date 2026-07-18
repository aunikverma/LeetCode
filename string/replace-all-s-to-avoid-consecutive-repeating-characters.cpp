class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 && s[i] == '?') {
                for (int j = 0; j < 26; j++) {
                    if ('a' + j != s[i + 1]) {
                        s[i] = 'a' + j;
                        break;
                    }
                }
            } else if (i == s.length() - 1 && s[i] == '?') {
                for (int j = 0; j < 26; j++) {
                    if ('a' + j != s[i - 1]) {
                        s[i] = 'a' + j;
                        break;
                    }
                }
            } else if (s[i] == '?') {
                for (int j = 0; j < 26; j++) {
                    if ('a' + j != s[i + 1] && 'a' + j != s[i - 1]) {
                        s[i] = 'a' + j;
                        break;
                    }
                }
            }
        }
        return s;
    }
};