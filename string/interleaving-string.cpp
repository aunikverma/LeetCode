class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        // base case
        if (m + n != s3.length()) {
            return false;
        }
        vector<int> prev(n + 1, 0);
        // both string are empty
        prev[0] = true;

        for (int i = 0; i <= m; i++) {
            // false to all
            vector<int> curr(n + 1, 0);
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = true;
                    continue;
                }
                int k = i + j - 1;
                if (i > 0 && s1[i - 1] == s3[k] && prev[j]) {
                    curr[j] = true;
                }
                if (j > 0 && s2[j - 1] == s3[k] && curr[j - 1]) {
                    curr[j] = true;
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};