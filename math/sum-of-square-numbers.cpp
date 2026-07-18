class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = (long long)sqrt(c);
        while (l <= r) {
            long long sum = (l * l) + (r * r);
            if (sum == c) {
                return true;
            } else if (sum > c) {
                r -= 1;
            } else {
                l += 1;
            }
        }
        return false;
    }
};