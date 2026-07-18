class Solution {
public:
    int M = 1e9 + 7;
    // binary exponentiation fot fermat little theorem
    long long power(long long a, long long b) {
        if (b == 0) {
            return 1;
        }
        long long half = power(a, b / 2);
        long long result = (half * half) % M;
        if (b % 2 == 1) {
            result = (result * a) % M;
        }
        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int blockSize = ceil(sqrt(n));

        unordered_map<int, vector<vector<int>>> Smallk;

        for (auto& q : queries) {
            int L = q[0], R = q[1];
            int k = q[2], V = q[3];

            if (k >= blockSize) {
                for (int i = L; i <= R; i += k) {
                    nums[i] = (1LL * nums[i] * V) % M;
                }
            } else {
                Smallk[k].push_back(q);
            }
        }

        for (auto& [k, allQuery] : Smallk) {
            vector<long long> diff(n, 1);

            for (auto& q : allQuery) {
                int L = q[0], R = q[1], V = q[3];

                diff[L] = (diff[L] * V) % M;

                int steps = (R - L) / k;
                int next = L + (steps + 1) * k;

                if (next < n) {
                    diff[next] = (diff[next] * power(V, M - 2) % M);
                }
            }
            // cummulative product
            for (int i = 0; i < n; i++) {
                if (i - k >= 0) {
                    diff[i] = (diff[i] * diff[i - k]) % M;
                }
            }

            // Apply diff to nums
            for (int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % M;
            }
        }

        int result = 0;
        for (int i : nums) {
            result ^= i;
        }
        return result;
    }
};