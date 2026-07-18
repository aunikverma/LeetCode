class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i = x,j = x + k - 1;
        while(i <= j)
        {
            int r = i,r1 = j;
            for(int c = y;c < y + k;c++)
            {
                swap(grid[r][c],grid[r1][c]);
            }
            i++;j--;
        }
        return grid;
    }
};