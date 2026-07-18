class Solution {
private:
    bool Vowel(char q) {
        if (q == 'a' || q == 'e' || q == 'i' || q == 'o' || q == 'u') {
            return true;
        }
        return false;
    }

public:
    int maxVowels(string s, int k) {
        int r = 0;
        for (int i = 0; i < k; i++) {
            if (Vowel(s[i])) {
                r++;
            }
        }
        int m = r;
        for (int i = k; i < s.length(); i++) {
            if (Vowel(s[i - k])) {
                r--; // if the one we removing is vowel then -1
            }
            if (Vowel(s[i])) {
                r++; // if the one we add is vowel then +1
            }
            m = max(m, r);
        }
        return m;
    }
};