class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid(3, vector<int>(3, 0));
        for (int i = 0; i < moves.size(); ++i)
            grid[moves[i][0]][moves[i][1]] = (i % 2 == 0) ? 1 : 2;

        // rows and cols
        for (int i = 0; i < 3; ++i) {
            if (grid[i][0] != 0 && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
                return grid[i][0] == 1 ? "A" : "B";
            if (grid[0][i] != 0 && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
                return grid[0][i] == 1 ? "A" : "B";
        }

        // diagonals
        if (grid[1][1] != 0) {
            if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
                return grid[1][1] == 1 ? "A" : "B";
            if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
                return grid[1][1] == 1 ? "A" : "B";
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
