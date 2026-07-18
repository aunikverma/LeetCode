class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s == goal) {
            return true;
        }
        int n = s.length() - 1;
        for (int i = 1; i <= n; i++) {
            reverse(s.begin(), s.end());
            reverse(s.begin(), s.begin() + n); // roating everytime by 1
            if (s == goal) {
                return true;
            }
        }
        return false;
    }
};