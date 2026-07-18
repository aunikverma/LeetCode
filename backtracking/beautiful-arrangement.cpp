class Solution {
public:
    int count;

    void solve(int ind, vector<bool>& used, int n) {
        if (ind > n) {
            count++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (ind % i == 0 || i % ind == 0)) {
                used[i] = true;
                solve(ind + 1, used, n);
                used[i] = false;
            }
        }
    }

    int countArrangement(int n) {
        count = 0;
        vector<bool> used(n + 1, false);
        solve(1, used, n);
        return count;
    }
};