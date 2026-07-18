class Solution {
public:
    string generateTheString(int n) {
        if (n == 1) {
            return "a";
        }
        string ans = "a";
        if (n % 2 == 0) {
            for (int i = 0; i < n - 1; i++) {
                ans += 'b';
            }
        } else {
            ans += 'b';
            for (int i = 0; i < n - 2; i++) {
                ans += 'c';
            }
        }
        return ans;
    }
};