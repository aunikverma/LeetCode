class Solution {
public:
    int maxPower(string s) {
        int ans = 1; // minimum power is always 1
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
                ans = max(ans, count);
            } else {
                count = 1; // reset count
            }
        }
        return ans;
    }
};