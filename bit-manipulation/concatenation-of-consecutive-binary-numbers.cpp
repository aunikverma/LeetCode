class Solution {
public:
    int concatenatedBinary(int n) {
        int M = 1e9 + 7;
        long long result = 0;
        int digits = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                digits++;
            }
            result = ((result << digits) % M + i) % M;
        }
        return (int)result;
    }
};
// using power of two