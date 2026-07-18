class Solution {
private:
    bool check(vector<vector<int>>& board, int r, int c, int m, int n,vector<vector<int>>& directions) {
        int count = 0;
        for (auto j : directions) {
            int r_q = r + j[0];
            int c_q = c + j[1];
            if (r_q >= 0 && r_q < m && c_q >= 0 && c_q < n) {
                if (board[r_q][c_q] == 1)
                    count++;
            }
        }
        if (board[r][c] == 1) {
            // live cell
            if (count < 2 || count > 3) return false;
            else return true;
        } else {
            // dead cell
            if (count == 3) return true;
            else return false;
        }
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0},{0, -1},{0, 1},{-1, -1}, {1, -1},{-1, 1}, {1, 1}}; // alldirection
        int m = board.size();  // rows
        int n = board[0].size(); // columns
        vector<vector<int>>next = board;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool v = check(board, i, j, m, n, directions);
                next[i][j] = (v) ? 1 : 0; //if true then 1 else 0
            }
        }
        board = next;
    }
};