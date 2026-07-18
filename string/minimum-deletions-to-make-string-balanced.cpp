class Solution {
public:
    int minimumDeletions(string s) {
        int count_a = 0;
        for (char c : s) {
            if (c == 'a') {
                count_a++;
            }
        }
        int count_b = 0;
        int ans = INT_MAX;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                count_a--;
            }
            ans = min(ans, count_a + count_b);
            if (s[i] == 'b') {
                count_b++;
            }
        }
        return ans;
    }
};
// count min(a on right side of i + b on left side of i)