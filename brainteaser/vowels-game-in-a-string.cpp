class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true; // alice wins(either 1-if contains odd take all or 2- even then take n-1)
            }
        }
        return false; // count of vowel is 0 therefore bob wins
    }
};