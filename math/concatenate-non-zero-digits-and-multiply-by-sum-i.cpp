class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long ans = 0;
        long long mul = 1;
        while (n > 0) {
            int r = n % 10;
            if (r != 0) {
                ans += (mul * r);
                sum += r;
                mul *= 10;
            }
            n /= 10;
        }
        return (ans * sum);
    }
};