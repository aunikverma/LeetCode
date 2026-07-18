class Solution {
public:
    void erathosenes(vector<bool>& prime) {
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= 1000; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= 1000; j += i) {
                    prime[j] = false;
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        // primes
        vector<bool> prime(1001, true);
        erathosenes(prime);

        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                bool v = false;
                for (int j = 2; j < nums[i]; j++) {
                    if (prime[j] && (nums[i] - j) < nums[i + 1]) {
                        nums[i] = nums[i] - j;
                        v = true;
                        break;
                    }
                }
                if (!v) {
                    return false;
                }
            }
        }
        return true;
    }
};