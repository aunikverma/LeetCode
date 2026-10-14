class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<int> next(2 * n + 1, 0);

        next[0] = true;

        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(2 * n + 1, 0);
            for (int balance = 0; balance <= (i * 2 + 1); balance++) {
                if (s[i] != '*') {
                    int n_balance = balance + (s[i] == '(' ? 1 : -1);
                    if (n_balance >= 0) {
                        curr[balance] = next[n_balance];
                    }
                } else {
                    curr[balance] = (curr[balance] || next[balance]);
                    curr[balance] = (curr[balance] || next[balance + 1]);
                    if (balance - 1 >= 0) {
                        curr[balance] = (curr[balance] || next[balance - 1]);
                    }
                }
            }
            next = curr;
        }
        return next[0];
    }
};