class Solution {
private:
    bool lucky(vector<vector<int>>& mat, int k, int a) {
        int m = INT_MIN;
        int r = mat.size();
        for (int i = 0; i < r; i++) {
            m = max(m, mat[i][k]);
        }
        return (m == a);
    }

public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int r = matrix.size();
        int c = matrix[0].size();
        for (int i = 0; i < r; i++) {
            int m = INT_MAX;
            int k = 0;
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] < m) {
                    m = matrix[i][j];
                    k = j;
                }
            }
            if (lucky(matrix, k, m)) {
                ans.push_back(m);
            }
        }
        return ans;
    }
};