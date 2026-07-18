class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = INT_MIN;
        int row = accounts.size();
        int col = accounts[0].size();
        for (int i = 0; i < row; i++) {
            int s = 0;
            for (int j = 0; j < col; j++) {
                s += accounts[i][j];
            }
            m = max(m, s);
        }
        return m;
    }
};