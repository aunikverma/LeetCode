class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size() - 1;
        double r = 51;
        while(i < j)
        {
            double a = (double) (nums[i] + nums[j]) / (double) 2;
            r = min(r,a);
            i++;
            j--;
        }
        return r;
    }
};