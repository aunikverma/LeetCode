class Solution {
public:
    bool checkGoodInteger(int n) {
        int sq_sum = 0, digit_sum = 0;
        while (n > 0) {
            int r = n % 10;
            digit_sum += r;
            sq_sum += (r * r);
            n /= 10;
        }
        return ((sq_sum - digit_sum) >= 50);
    }
};