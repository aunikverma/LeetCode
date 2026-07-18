class Solution {
private:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > i) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
        }
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            for (int k = 0; k < n; k++) {
                swap(mat[k][i], mat[k][j]);
            }
            i++;
            j--;
        } // rotated by 90 degress
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<vector<int>>> ans;
        ans.push_back(mat);
        for (int i = 0; i < 3; i++) {
            rotate(mat);
            ans.push_back(mat);
        }
        for (int i = 0; i < 4; i++) {
            if (ans[i] == target) {
                return true;
            }
        }
        return false;
    }
};