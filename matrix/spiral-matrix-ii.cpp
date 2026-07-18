class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int count = 0;
        int c1 = 1;
        int total = n*n;
        int strow = 0;       // starting row
        int stcol = 0;       // starting column
        int enrow = n - 1; // ending row
        int encol = n - 1; // ending column
        while (count < total) {
            // printing starting row
            for (int i = stcol; count < total && i <= encol; i++) {
                matrix[strow][i] = c1;
                c1++;
                count++;
            }
            // updating strow
            strow++;
            // printing ending column
            for (int i = strow; count < total && i <= enrow; i++) {
                matrix[i][encol] = c1;
                c1++;
                count++;
            }
            // updating encol
            encol--;
            // printing ending row
            for (int i = encol; count < total && i >= stcol; i--) {
                matrix[enrow][i] = c1;
                c1++;
                count++;
            }
            // updating enrow
            enrow--;
            // printing starting column
            for (int i = enrow; count < total && i >= strow; i--) {
                matrix[i][stcol] = c1;
                c1++;
                count++;
            }
            // updating starting column
            stcol++;
        }
        return matrix;
    }
};