class Solution {
public:
    int n;
    int Mod = 1e9 + 7;
    pair<int, int> solve(int i, int j, vector<string>& board,
                         vector<vector<pair<int, int>>>& dp) {
        if (i == 0 && j == 0) {
            return {0, 1};
        }
        if (dp[i][j] != make_pair(-1, -1)) {
            return dp[i][j];
        }
        pair<int, int> up = {0, 0};
        pair<int, int> left = {0, 0};
        pair<int, int> dig = {0, 0};
        int val = board[i][j] - '0';
        // up
        if (i - 1 >= 0 && board[i - 1][j] != 'X') {
            auto [score, paths] = solve(i - 1, j, board, dp);
            score += val;
            up.first = score;
            up.second = paths;
        }
        // left
        if (j - 1 >= 0 && board[i][j - 1] != 'X') {
            auto [score, paths] = solve(i, j - 1, board, dp);
            score += val;
            left.first = score;
            left.second = paths;
        }
        // dig
        if (j - 1 >= 0 && i - 1 >= 0 && board[i - 1][j - 1] != 'X') {
            auto [score, paths] = solve(i - 1, j - 1, board, dp);
            score += val;
            dig.first = score;
            dig.second = paths;
        }
        int best_score = 0;
        // we find best score only if it leads to (0,0)
        if (up.second > 0) {
            best_score = max(best_score, up.first);
        }
        if (left.second > 0) {
            best_score = max(best_score, left.first);
        }
        if (dig.second > 0) {
            best_score = max(best_score, dig.first);
        }
        // only paths which have best_score will be added to ans
        int paths = 0;
        paths = (paths + (up.first == best_score ? up.second : 0)) % Mod;
        paths = (paths + (left.first == best_score ? left.second : 0)) % Mod;
        paths = (paths + (dig.first == best_score ? dig.second : 0)) % Mod;

        return dp[i][j] = {best_score, paths};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        board[n - 1][n - 1] = board[0][0] = '0';
        vector<vector<pair<int, int>>> dp(
            n + 1, vector<pair<int, int>>(n + 1, {-1, -1}));
        auto [score, paths] = solve(n - 1, n - 1, board, dp);
        return {score, paths};
    }
};