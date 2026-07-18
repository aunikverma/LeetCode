class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxArea = 0;
        vector<pair<int, int>> prevHeights;

        for (int r = 0; r < m; r++) {
            vector<pair<int, int>> currHeight;
            vector<bool> seen(n, false);
            for (auto [height, col] : prevHeights) {
                if (matrix[r][col] == 1) {
                    currHeight.push_back({height + 1, col});
                    seen[col] = true;
                }
            }
            for (int c = 0; c < n; c++) {
                if (!seen[c] && matrix[r][c] == 1) {
                    currHeight.push_back({1, c});
                }
            }
            for (int i = 0; i < currHeight.size(); i++) {
                maxArea = max(maxArea, currHeight[i].first * (i + 1));
            }
            prevHeights = currHeight;
        }
        return maxArea;
    }
};