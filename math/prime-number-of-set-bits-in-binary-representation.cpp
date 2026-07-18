class Solution {
private:
    bool prime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int c = __builtin_popcount(i);
            if (prime(c)) {
                ans++;
            }
        }
        return ans;
    }
};