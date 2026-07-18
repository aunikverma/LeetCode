class Solution {
public:
    bool detectCapitalUse(string w) {
        int n = w.length();
        int a = 0; // for all capital
        for (char c : w) {
            if (c >= 'A' && c <= 'Z') {
                a++;
            }
        }
        if ((w[0] >= 'A' && w[0] <= 'Z' && a == 1) || a == n || a == 0) {
            return true;
        }
        return false;
    }
};