class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        int commas = 1;
        while (start <= n && commas <= 4) {
            long long end = (start * 1000) - 1;
            long long upper = min(n, end);
            ans += (upper - start + 1) * commas;
            start *= 1000;
            commas++;
        }
        // handle last one
        if (n == (long long)1e15) {
            ans += 5;
        }
        return ans;
    }
};