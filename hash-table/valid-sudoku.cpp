class Solution {
private:
    bool isSafe(vector<vector<char>>& board, int row, int col, int n) {
        set<char> r; // row
        set<char> c; // col
        set<char> g; // grid
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 0; i < n; i++) {
            if (board[row][i] != '.') // row
            {
                c1++;
                r.insert(board[row][i]);
            }
            if (board[i][col] != '.') // col
            {
                c2++;
                c.insert(board[i][col]);
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.') {
                c3++;
                g.insert(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3]);
            }
        }
        return (c1 == r.size() && c2 == c.size() && c3 == g.size());
    }

    bool solve(vector<vector<char>>& board) {
        int n = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    if (!isSafe(board, i, j, n)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) { return solve(board); }
};