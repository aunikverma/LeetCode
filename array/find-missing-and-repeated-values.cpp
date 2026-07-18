class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(2,0);
        int n = grid.size();
        vector<int>vec(n*n,0);
        for(int i = 0;i <n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                vec[grid[i][j] - 1]++;
            }
        }
        for(int i = 0;i < vec.size();i++)
        {
            if(vec[i] == 0)
            {
                ans[1] = i+1;
            }
            if(vec[i] == 2)
            {
                ans[0] = i+1;
            }
        }
        return ans;
    }
};