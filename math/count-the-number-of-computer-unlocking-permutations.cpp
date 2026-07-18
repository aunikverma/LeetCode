class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        const int mod = 1e9 + 7;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
            ans = (1LL * (ans % mod) * (i % mod)) % mod;
        }
        return ans;
    }
};