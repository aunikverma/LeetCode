class Solution {
public:
    int countHomogenous(string s) {
        int Mod = 1e9 + 7;
        int count = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s[i] != s[i - 1]) {
                count = 1;
            } else {
                count += 1;
            }
            ans = (ans + count) % Mod;
        }
        return ans;
    }
};