class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<int> dx = {0, -1, -1, -1, 0, 1, 1, 1};
        vector<int> dy = {-1, -1, 0, 1, 1, 1, 0, -1};
        int row = img.size();
        int col = img[0].size();
        vector<vector<int>> ans(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int count = 1, sum = img[i][j];
                for (int k = 0; k < 8; k++) {
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if (nr >= 0 && nc >= 0 && nr < row && nc < col) {
                        sum += img[nr][nc];
                        count++;
                    }
                }
                ans[i][j] = sum / count;
            }
        }
        return ans;
    }
};