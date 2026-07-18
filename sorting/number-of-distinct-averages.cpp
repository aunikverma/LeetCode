class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double>s;
        sort(nums.begin(),nums.end());
        int i = 0,j = nums.size() - 1;
        while(i < j)
        {
            double a = (double)(nums[i] + nums[j]) / 2;
            s.insert(a);
            i++;j--;
        }
        return s.size();
    }
};