class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        // if first
        if (s[0] - '0' == x) {
            return false;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] - '0' == x) {
                return true;
            }
        }
        return false;
    }
};