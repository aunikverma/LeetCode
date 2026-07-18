class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int> dp(strs[0].length(), 1);
        int lis = 1;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 0; j < i; j++) {
                bool safe = true;
                for (int k = 0; k < strs.size(); k++) {
                    if (strs[k][j] > strs[k][i]) {
                        safe = false;
                        break;
                    }
                }
                if (safe) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            lis = max(lis, dp[i]); // max lis for strings
        }
        return (strs[0].length() - lis); // minimum deletion
    }
};