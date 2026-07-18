class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // Step 1: compute max for each column
        vector<int> colMax(cols, INT_MIN);
        vector<pair<int, int>> nones; // (row, col)
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == -1)
                    nones.push_back({r, c});
                colMax[c] = max(colMax[c],matrix[r][c]); // changing if any bigger val in next row
            }
        }
        // Step 2: replace -1 with column max
        for (auto& p : nones) {
            int r = p.first, c = p.second;
            matrix[r][c] = colMax[c];
        }
        return matrix;
    }
};
