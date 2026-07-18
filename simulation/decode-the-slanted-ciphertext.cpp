class Solution {
public:
    string decodeCiphertext(string text, int rows) {
        int cols = text.length() / rows;
        vector<vector<char>> mat(rows, vector<char>(cols));
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = text[k++];
            }
        }
        string ans = "";
        for (int i = 0; i < cols; i++) // cols
        {
            int r_q = 0, c_q = i;
            while (r_q < rows && c_q < cols) {
                ans += mat[r_q][c_q];
                r_q++;
                c_q++;
            }
        }
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back(); // removing trailing spaces
        }
        return ans;
    }
};