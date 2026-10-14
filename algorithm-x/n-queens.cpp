class Solution {
private:
    void addsolution(vector<vector<string>>& ans, vector<vector<int>>& board,int n) {
        vector<string> temp(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 1)
                    temp[i][j] = 'Q';
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, int n, vector<vector<int>>& board) {
        int x = row, y = col;
        // check for same row(since we are putting queens from left to right)
        while (y >= 0) {
            if (board[x][y] == 1) return false;
            y--;
        }
        x = row, y = col;
        while (x >= 0 && y >= 0) // upper left dia
        {
            if (board[x][y] == 1) return false;
            x--;
            y--;
        }
        x = row, y = col;
        while (x < n && y >= 0) // down left dia
        {
            if (board[x][y] == 1) return false;
            x++;
            y--;
        }
        return true;
    }

    void solve(int col, int n, vector<vector<string>>& ans,
               vector<vector<int>>& board) {
        // base case
        if (col == n) {
            addsolution(ans, board, n);
            return;
        }

        // solve 1 case rest recursion
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 1; // put
                solve(col + 1, n, ans, board);
                board[row][col] = 0; // take (backtrack)
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(0, n, ans, board);
        return ans;
    }
};