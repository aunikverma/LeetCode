class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> prime(n + 1, true); // sieve of erathosenes
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ans += 1;
                for (int j = i * 2; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return ans;
    }
};