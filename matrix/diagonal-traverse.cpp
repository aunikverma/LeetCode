class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> ans;
        map<int, vector<int>> mp; //stored sum of i + j in sorted order 
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        for (auto& v : mp) {
            auto arr = v.second;
            if (v.first % 2 == 0) {
                for (int i = arr.size() - 1; i >= 0; i--) {
                    ans.push_back(arr[i]);
                }
            } else {
                for (int i : arr) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};
//0 : 1 ,when sum is zero we reversed
//1 : 2,4
//2 : 3,5,7
//3 : 6,8
//4 : 9 
