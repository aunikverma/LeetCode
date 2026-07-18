class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int s = 0;
        if (n == 1) {
            return mat[0][0];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    s += mat[i][j];
                } else if (i == (n - j - 1)) {
                    s += mat[i][j];
                }
            }
        }
        return s;
    }
};