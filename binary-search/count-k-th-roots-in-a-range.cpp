class Solution {
public:
    long long Root_floor(long long n, int k) {
        long long l = 1, r = n, ans = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            unsigned long long val = 1;
            for (int i = 0; i < k; i++) {
                val *= mid;
                if (val > n) {
                    break;
                }
            }
            if (val <= n) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    long long Root_ceil(long long n, int k) {
        long long l = 1, r = n, ans = n + 1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            unsigned long long val = 1;
            for (int i = 0; i < k; i++) {
                val *= mid;
                if (val > n) {
                    break;
                }
            }
            if (val >= n) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int countKthRoots(int l, int r, int k) {
        long long upper = Root_floor(r, k);
        long long lower = (l == 0 ? 0 : Root_ceil(l, k));
        return (upper < lower ? 0 : (int)(upper - lower + 1));
    }
};
//l <= x^k <= r
// l^ (1/k) upper bound <= x <= lower bound r ^ (1 / k);
//finding using binary search
