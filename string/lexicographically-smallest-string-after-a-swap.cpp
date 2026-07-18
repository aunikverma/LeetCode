class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            int c = s[i] - '0';
            int n = s[i + 1] - '0';
            if ((c % 2 == 0 && n % 2 == 0) || (c % 2 != 0 && n % 2 != 0)) {
                if (c > n) {
                    swap(s[i], s[i + 1]);
                    break;
                }
            }
        }
        return s;
    }
};