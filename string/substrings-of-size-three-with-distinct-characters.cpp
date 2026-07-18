class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.length() < 3) {
            return false;
        }
        int ans = 0;
        for (int i = 0; i < s.length() - 2; i++) {
            string a = s.substr(i, 3);
            if (a[0] != a[1] && a[0] != a[2] && a[1] != a[2]) {
                ans++;
            }
        }
        return ans;
    }
};