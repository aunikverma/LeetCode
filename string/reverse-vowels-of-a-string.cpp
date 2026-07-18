class Solution {
public:
    bool vowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (vowel(s[i]) && vowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            if (vowel(s[i]) == false) {
                i++;
            }
            if (vowel(s[j]) == false) {
                j--;
            }
        }
        return s;
    }
};