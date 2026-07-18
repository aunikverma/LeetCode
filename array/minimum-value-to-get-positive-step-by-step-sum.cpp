class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int min_value = 0;
        int prev_sum = 0;
        for(int i = 0;i < n; i++)
        {
            prev_sum = prev_sum + nums[i];
            min_value = min(prev_sum,min_value);
        }
        return (1 - min_value);
    }
};