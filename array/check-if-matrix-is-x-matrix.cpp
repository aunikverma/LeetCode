class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == n - j - 1 || i == j) { //if diagonal and zero return false
                    if(matrix[i][j] == 0) return false;
                }
                else{ //if non diagonal and non zero return false
                    if(matrix[i][j] != 0) return false;
                }
            }
        }
        return true;
    }
};