class Solution {
public:
    typedef long long ll;
    int M = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> non_zero(n, 0);
        vector<ll> pow10(n + 1, 0);
        vector<ll> digit_sum(n, 0);
        vector<ll> number(n, 0);

        // power
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        // filling pre-requisite arrays
        number[0] = s[0] - '0';
        digit_sum[0] = s[0] - '0';
        non_zero[0] = (s[0] - '0' > 0 ? 1 : 0);

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            non_zero[i] = (digit > 0 ? 1 : 0) + non_zero[i - 1];
            digit_sum[i] = digit_sum[i - 1] + digit;
            number[i] = (digit > 0 ? ((number[i - 1] * 10) + digit) % M
                                   : number[i - 1]);
        }

        // filling ans
        int q = queries.size();
        vector<int> ans(q, 0);

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int sum = digit_sum[r] - (l == 0 ? 0 : digit_sum[l - 1]);

            int k = non_zero[r] - (l == 0 ? 0 : non_zero[l - 1]);
            int no_before = (l == 0 ? 0 : number[l - 1]);
            ll x = (number[r] - (no_before * pow10[k] % M) + M) % M;

            ans[i] = (sum * x) % M;
        }
        return ans;
    }
};