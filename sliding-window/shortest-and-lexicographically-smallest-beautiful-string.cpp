class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int ones = 0;
        int l = 0;
        string ans = "";
        for (int r = 0; r < n; r++) {
            ones += (s[r] == '1');
            while (ones >= k) {
                string s_new = s.substr(l, r - l + 1);
                if (ans.empty() || s_new.length() < ans.length() ||
                    (s_new.length() == ans.length() && s_new < ans)) {
                    ans = s_new;
                }
                // shrink window
                ones -= (s[l] == '1');
                l++;
            }
        }
        return ans;
    }
};