class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int ans = INT_MAX;
        int f1 = 0, f2 = 0;
        int i = 0, j = 0;
        // sliding window
        while (j < 2 * n) {
            if (s[j % n] != (j % 2 == 0 ? '0' : '1')) {
                f1++;
            }
            if (s[j % n] != (j % 2 == 0 ? '1' : '0')) {
                f2++;
            }
            // shrink the window from left
            if (j - i + 1 > n) {
                if (s[i % n] != (i % 2 == 0 ? '0' : '1')) {
                    f1--;
                }
                if (s[i % n] != (i % 2 == 0 ? '1' : '0')) {
                    f2--;
                }
                i++;
            }
            if (j - i + 1 == n) {
                ans = min(ans, min(f1, f2));
            }
            j++;
        }
        return ans;
    }
};
// final string 010101.. or 101010..
// f1 and f2 are no of flips reqd to change to s1 and s2