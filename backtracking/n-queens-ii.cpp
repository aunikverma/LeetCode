class Solution {
public:
    bool safety(int row, int col, int n, vector<string>& board) {
        if (col == 0 || col == n)
            return true;
        int r = row;
        int c = col;
        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q')
                return false;
        }
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        r = row;
        c = col;
        while (r <= n - 1 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(int col, int n, int& ans, vector<string>& board) {
        if (col == n) {
            ans++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (safety(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col + 1, n, ans, board);
                board[row][col] = '.';
            }
        }
        return;
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        solve(0, n, ans, board);
        return ans;
    }
};