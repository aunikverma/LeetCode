class Solution {
public:
    void reverse(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < j) {
            for (int k = 0; k < m; k++) {
                swap(matrix[k][i], matrix[k][j]);
            }
            i++;
            j--;
        }
    }

    void transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};