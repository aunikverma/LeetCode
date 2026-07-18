class Solution {
private:
    bool isvowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    bool halvesAreAlike(string s) {
        int st = 0;
        int e = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            if (isvowel(s[i])) {
                st++;
            }
            if (isvowel(s[s.length() - i - 1])) {
                e++;
            }
        }
        return (st == e);
    }
};