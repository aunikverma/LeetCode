class Solution {
    int sum(int a, int k) {
        int s = 0;
        while (a > 0) {
            int r = a % k;
            s += r;
            a /= k;
        }
        return s;
    }

public:
    int sumBase(int n, int k) { return sum(n, k); }
};