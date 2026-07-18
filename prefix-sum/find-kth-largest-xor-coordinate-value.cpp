class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i > 0) matrix[i][j] ^= matrix[i - 1][j]; //take its left
                if (j > 0) matrix[i][j] ^= matrix[i][j - 1]; //take its above
                if (i > 0 && j > 0) matrix[i][j] ^= matrix[i - 1][j - 1]; //take its upper left
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};