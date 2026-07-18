class Solution {
public:
    vector<int> t;

    int solve(int n) {
        if (t[n] != -1) {
            return t[n];
        }
        if (n == 0) {
            return t[n] = 0;
        }
        int remain = solve(n / 10);
        if (remain == 2) {
            return t[n] = 2;
        }
        int r = n % 10;
        int digit_check;
        if (r == 0 || r == 1 || r == 8) {
            digit_check = 0;
        } else if (r == 2 || r == 5 || r == 6 || r == 9) {
            digit_check = 1; // good
        } else {
            return t[n] = 2; // invalid
        }
        // same
        if (remain == 0 && digit_check == 0) {
            return t[n] = 0;
        }
        return t[n] = 1;
    }

    int rotatedDigits(int n) {
        int count = 0;
        t.resize(n + 1, -1);
        for (int i = 2; i <= n; i++) {
            if (solve(i) == 1) {
                count++;
            }
        }
        return count;
    }
};
// 0 same
// 1 changed
// 2 invalid