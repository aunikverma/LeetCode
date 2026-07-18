class Solution {
public:
    long long minTime(vector<int>& w,
                      vector<int>& p) {     // w : wizard, p : potion
        int m = p.size();                   // potions
        int n = w.size();                   // wizards
        vector<long long> finishtime(n, 0); // wizard finish time
        for (int j = 0; j < m; j++) {
            finishtime[0] += p[j] * w[0];
            for (int i = 1; i < n; i++) {
                finishtime[i] =
                    max(finishtime[i], finishtime[i - 1]) + (1LL * p[j] * w[i]); //step 2
            }
            // synchronisation
            for (int i = n - 1; i > 0; i--) {
                finishtime[i - 1] = finishtime[i] - (1LL * p[j] * w[i]); //step - 3
            }
        }
        return finishtime[n - 1];
    }
};