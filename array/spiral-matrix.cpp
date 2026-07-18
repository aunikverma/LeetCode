class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int total = row*col;
        int strow = 0;//starting row
        int stcol = 0;//starting column
        int enrow = row - 1;//ending row
        int encol = col - 1;//ending column
        while(count < total)
        {
            //printing starting row
            for(int i = stcol;count < total && i <= encol;i++)
            {
                ans.push_back(matrix[strow][i]);
                count++;
            }
            //updating strow
            strow++;
            //printing ending column
            for(int i = strow;count < total && i <= enrow;i++)
            {
                ans.push_back(matrix[i][encol]);
                count++;
            }
            //updating encol
            encol--;
            //printing ending row
            for(int i = encol;count < total && i >= stcol;i--)
            {
                ans.push_back(matrix[enrow][i]);
                count++;
            }
            //updating enrow
            enrow--;
            //printing starting column
            for(int i = enrow;count < total && i >= strow;i--)
            {
                ans.push_back(matrix[i][stcol]);
                count++;
            }
            //updating starting column
            stcol++;
        }
        return ans;
    }
};