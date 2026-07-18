class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int n = matrix.size(), count = 0, min_abs = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    count++;
                }
                min_abs = min(min_abs, abs(matrix[i][j]));
            }
        }
        if (count % 2 == 1) {
            sum -= 2 * min_abs;
        }
        return sum;
    }
};