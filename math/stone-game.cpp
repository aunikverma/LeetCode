class Solution {
public:
    int solve(int i, int j, int turn, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j][turn] != -1) {
            return dp[i][j][turn];
        }
        if (turn) {
            int move1 = piles[i] + solve(i + 1, j, 1 - turn, piles, dp);
            int move2 = piles[j] + solve(i, j - 1, 1 - turn, piles, dp);
            return dp[i][j][turn] = max(move1, move2);
        }
        int move1 = -piles[i] + solve(i + 1, j, 1 - turn, piles, dp);
        int move2 = -piles[j] + solve(i, j - 1, 1 - turn, piles, dp);
        return dp[i][j][turn] = max(move1, move2);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3, -1)));
        return solve(0, n - 1, 1, piles, dp);
    }
};