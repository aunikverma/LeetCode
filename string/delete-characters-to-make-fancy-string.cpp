class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] != s[i - 1]) {
                c = 1;
                ans += s[i];
            } else if (c < 2) {
                c++;
                ans += s[i];
            }
        }
        return ans;
    }
};