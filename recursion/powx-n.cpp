class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double half = pow(x, n / 2);
        double ans = half * half;
        if (n & 1) {
            ans *= x;
        }
        return ans;
    }

    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / pow(x, n);
        }
        return pow(x, n);
    }
};