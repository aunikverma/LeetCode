class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int mod = 1e9 + 7; // to handle overflow
        vector<int> a(n, 1);

        for (int j = 0; j < k; j++) {
            for (int i = 1; i < n; i++) {
                a[i] = (a[i - 1] + a[i]) % mod;
            }
        }

        return a[n - 1];
    }
};