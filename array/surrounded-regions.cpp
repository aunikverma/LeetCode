class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != 'O')
            return;

        board[i][j] = 'S'; // mark as safe (connected to border)
        dfs(board, i + 1, j, row, col);
        dfs(board, i - 1, j, row, col);
        dfs(board, i, j + 1, row, col);
        dfs(board, i, j - 1, row, col);
    }

public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        // 1. Start DFS from all border 'O's
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((i == 0 || j == 0 || i == row - 1 || j == col - 1) &&
                    board[i][j] == 'O')
                    dfs(board, i, j, row, col);
            }
        }

        // 2. Convert all remaining 'O' → 'X', and all 'S' → 'O'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};
