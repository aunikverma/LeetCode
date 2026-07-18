class Solution {
public:
    int numSub(string s) {
        long long count = 0;
        long long ans = 0;
        long long mod = 1e9 + 7;
        long long inv2 = 500000004; // Modular inverse of 2 modulo 1e9+7
        for (int i = 0; i < s.length();) {
            if (s[i] == '1') {
                while (s[i] == '1') {
                    count++;
                    i++;
                }
                ans = (ans + (count * (count + 1) % mod) * inv2 % mod) % mod;
                count = 0;
            } else {
                i++;
            }
        }
        return int(ans);
    }
};