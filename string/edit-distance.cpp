class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = a.length(), n = b.length();
        // base case
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        // from base case
        for (int j = 0; j < n; j++) {
            next[j] = n - j;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // base case catch here
                curr[n] = m - i;
                if (a[i] == b[j]) {
                    curr[j] = next[j + 1];
                } else {
                    // insert
                    int insert_ans = 1 + curr[j + 1];
                    // replace
                    int replace_ans = 1 + next[j + 1];
                    // delete
                    int delete_ans = 1 + next[j];
                    // update
                    curr[j] = min({insert_ans, replace_ans, delete_ans});
                }
            }
            next = curr;
        }
        return curr[0];
    }
};