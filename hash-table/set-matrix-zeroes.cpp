class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> visitedRows(m, false);
        vector<bool> visitedCol(n, false);

        for(int i=0;i<m;i++) { //setting true when matrix[i][j] == 0
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==0) {
                    visitedRows[i]=true;
                    visitedCol[j]=true;
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(visitedRows[i] || visitedCol[j]) { //if in row i any element 0 then zero similar to column
                    matrix[i][j]=0;
                }
            }
        }
    }
};