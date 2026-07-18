class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) {
            return s;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            // for 1 and (n - 1) row
            int increment = 2 * (n - 1);
            for (int j = i; j < s.length(); j += increment) {
                ans += s[j];
                if (i > 0 && i < n - 1 &&
                    (j + increment - 2 * i) < s.length()) {
                    ans += s[j + increment - 2 * i];
                }
            }
        }
        return ans;
    }
};
