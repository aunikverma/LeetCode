class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> freq; // spell : frequency
        for (auto i : power) {
            freq[i]++;
        }
        unordered_map<int, long long> dp; // spell : dp value

        long long ans = 0, prev, backele = 0;

        for (auto& [i, f] : freq) // i : spell ,f : freq
        {
            auto backit = freq.lower_bound(i - 2); // spell - 2
            if (backit != freq.begin()) {
                backele = (*(--backit)).first; // just spell less than i(spell)
            }
            dp[i] = max(dp[prev], i * f + dp[backele]); // sum till dp[prev]
            ans = max(ans, dp[i]);
            prev = i;
        }
        return ans;
    }
};