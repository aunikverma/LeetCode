class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            int n = s.length();
            for (int i = 0; i < n - 1; i++) {
                int a = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                s += to_string(a);
            }
            s.erase(s.begin(), s.begin() + n);
        }
        return (s[0] == s[1]);
    }
};