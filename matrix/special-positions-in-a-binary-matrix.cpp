class Solution {
private:
    bool check(vector<vector<int>>& mat, int r, int c) {
        int row = 0, col = 0;
        for (int i = 0; i < mat[0].size(); i++) // row
        {
            row += mat[r][i];
        }
        for (int i = 0; i < mat.size(); i++) // col
        {
            col += mat[i][c];
        }
        return (row == 1 && col == 1);
    }

public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    if (check(mat, i, j))
                        count++;
                }
            }
        }
        return count;
    }
};