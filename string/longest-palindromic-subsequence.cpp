class Solution {
public:
    int solveTabSpace(string a, string b) {
        int n = a.length();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }
        return curr[0];
    }

    int longestPalindromeSubseq(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        return solveTabSpace(s, rev_s);
    }
};