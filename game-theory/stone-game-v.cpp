class Solution {
public:
    int dp[501][501];

    int solve(int l, int r, vector<int>& prefix) {
        if (l >= r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int score = 0;
        for (int mid = l; mid <= r - 1; mid++) {
            int left_sum = prefix[mid] - (l - 1 >= 0 ? prefix[l - 1] : 0);
            int right_sum = prefix[r] - (mid >= 0 ? prefix[mid] : 0);

            if (left_sum > right_sum) {
                score = max(score, right_sum + solve(mid + 1, r, prefix));
            } else if (right_sum > left_sum) {
                score = max(score, left_sum + solve(l, mid, prefix));
            } else {
                score = max(score, right_sum + solve(mid + 1, r, prefix));
                score = max(score, left_sum + solve(l, mid, prefix));
            }
        }
        return dp[l][r] = score;
    }

    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        // prefix sum array
        vector<int> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, prefix);
    }
};