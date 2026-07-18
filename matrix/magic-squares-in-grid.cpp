class Solution {
private:
    bool check(int row, int col, vector<vector<int>>& grid) {
        // Must contain digits 1–9 exactly once
        vector<int> magic(10, 0);
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9) {
                    return false;
                }
                magic[val]++;
            }
        }
        for (int k = 1; k <= 9; k++) {
            if (magic[k] != 1) {
                return false;
            }
        }

        // Check rows
        for (int i = 0; i < 3; i++) {
            int sum = grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2];
            if (sum != 15) {
                return false;
            }
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            int sum = grid[row][col + j] + grid[row + 1][col + j] + grid[row + 2][col + j];
            if (sum != 15) {
                return false;
            }
        }

        // Check diagonals
        int d1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int d2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        if (d1 != 15 || d2 != 15) {
            return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m * n < 9) {
            return 0;
        }
        int count = 0; // no of magic sq
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (check(i, j, grid)) {
                    count++;
                }
            }
        }
        return count;
    }
};
// since all rows and col must have same sum
// sum(1 - 9) = 45
// 45 / 3 = 15