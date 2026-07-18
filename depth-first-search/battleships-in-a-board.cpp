class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& board,
             vector<vector<bool>>& visited) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] ||
            board[i][j] == '.')
            return;

        visited[i][j] = true;

        dfs(i + 1, j, board, visited);
        dfs(i - 1, j, board, visited);
        dfs(i, j + 1, board, visited);
        dfs(i, j - 1, board, visited);
    }

public:
    int
    countBattleships(vector<vector<char>>& board) { // same like no of islands
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // visited
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'X') {
                    dfs(i, j, board, visited);
                    count++;
                }
            }
        }
        return count;
    }
};