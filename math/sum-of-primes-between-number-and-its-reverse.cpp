class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while (n > 0) {
            int r = n % 10;
            rev = rev * 10 + r;
            n /= 10;
        }
        return rev;
    }

    bool prime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int a = reverse(n);
        int sum_of_primes = 0;
        for (int i = min(n, a); i <= max(n, a); i++) {
            if (prime(i)) {
                sum_of_primes += i;
            }
        }
        return sum_of_primes;
    }
};