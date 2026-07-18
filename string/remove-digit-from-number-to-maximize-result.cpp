class Solution {
public:
    string removeDigit(string n, char d) {
        string ans = "";
        for (int i = 0; i < n.length(); i++) {
            if (n[i] == d) {
                string s = n.substr(0, i) + n.substr(i + 1);
                if (s > ans) {
                    ans = s;
                }
            }
        }
        return ans;
    }
};