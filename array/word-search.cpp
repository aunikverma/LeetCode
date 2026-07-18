class Solution {
private:
    bool dfs(int r, int c, int& m, int& n, vector<vector<char>>& board,
             string word, vector<vector<bool>>& visited,
             vector<vector<int>>& dir) {
        if (board[r][c] != word[0])
            return false;
        if (word.size() == 1)
            return true;

        visited[r][c] = true;
        for (auto& d : dir) {
            int sr = r + d[0];
            int sc = c + d[1];
            if (sr >= 0 && sr < m && sc >= 0 && sc < n && !visited[sr][sc]) {
                if (dfs(sr, sc, m, n, board, word.substr(1), visited, dir)) {
                    return true;
                }
            }
        }
        visited[r][c] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, m, n, board, word, visited, dir)) {
                    return true;
                }
            }
        }
        return false;
    }
};
