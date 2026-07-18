class Solution {
public:
    typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        ll actual_profit = 0;
        vector<ll> profit(n, 0);

        for (int i = 0; i < n; i++) {
            profit[i] = prices[i] * strategy[i];
            actual_profit += profit[i];
        }

        ll original_win = 0;
        ll mod_win = 0;
        ll maxGain = 0;

        // sliding window
        int i = 0, j = 0;
        while (j < n) {
            original_win += profit[j];

            if (j - i + 1 > k / 2) {
                mod_win += prices[j];
            }
            if (j - i + 1 > k) {
                original_win -= profit[i];
                mod_win -= prices[i + k / 2];
                i++;
            }
            // window of size k
            if (j - i + 1 == k) {
                maxGain = max(maxGain, mod_win - original_win);
            }
            j++;
        }
        return actual_profit + maxGain;
    }
};