class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int s = 0;//starting
        int e = row*col - 1;//ending
        while(s <= e)
        {
            int mid = s + (e - s)/2;//finding mid
            if(matrix[mid/col][mid%col] == target)//row = mid/col and col = mid%col
            {
                return true;
            }
            else if(matrix[mid/col][mid%col] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return false;
    }
};