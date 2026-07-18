class Solution {
public:
    int m, n;
    int dp[1001][1001];
    int solve(int i, int j, string& s1, string& s2) {
        if (i >= m && j >= n) { //both out of bound
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) { //if character same
            return dp[i][j] = solve(i + 1, j + 1, s1, s2);
        }
        if (i >= m) { //if i out of bound
            return dp[i][j] = s2[j] + solve(i, j + 1, s1, s2);
        }
        if (j >= n) {//if j  out of bound
            return dp[i][j] = s1[i] + solve(i + 1, j, s1, s2);
        }
        int del_i = s1[i] + solve(i + 1, j, s1, s2); //del i
        int del_j = s2[j] + solve(i, j + 1, s1, s2); //del j
        return dp[i][j] = min(del_i, del_j);
    }

    int minimumDeleteSum(string s1, string s2) {
        m = s1.length(), n = s2.length();
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0, 0, s1, s2);
    }
};