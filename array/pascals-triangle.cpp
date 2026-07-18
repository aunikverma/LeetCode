class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>> pascal(num);
        for (int i = 0; i < num; i++) {
            pascal[i].resize(i + 1);
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    pascal[i][j] = 1;
                } else {
                    pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
                }
            }
        }
        return pascal;
    }
};