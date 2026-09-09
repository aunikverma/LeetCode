class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) {
            return 0;
        }
        long long ans = 0;
        // 5 comma one case
        if (n == 1e15) {
            ans += 5;
        }
        // one comma
        if (n >= 1000 && n <= 999999) {
            ans += (n - 1000) + 1;
        }
        // two comma
        if (n >= 1000000 && n <= 999999999) {
            ans += ((n - 1000000) + 1) * 2;
        }
        // three comma
        if (n >= 1000000000 && n <= 999999999999) {
            ans += ((n - 1000000000) + 1) * 3;
        }
        // four comma
        if (n >= 1000000000000 && n <= 999999999999999) {
            ans += ((n - 1000000000000) + 1) * 4;
        }
        return ans;
    }
};