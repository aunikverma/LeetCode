class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c) {
            return mat; // Return the original matrix if reshaping is not possible
        }
        vector<int> d;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                d.push_back(mat[i][j]);
            }
        }
        int k = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = d[k];
                k++;
            }
        }
        return ans;
    }
};