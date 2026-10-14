class Solution {
public:
    bool checkDivisibility(int n) {
        int digit_sum = 0, digit_mul = 1;
        int num = n;
        while (n > 0) {
            int r = n % 10;
            digit_sum += r;
            digit_mul *= r;
            n /= 10;
        }
        return (num % (digit_sum + digit_mul) == 0);
    }
};