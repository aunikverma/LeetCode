class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //using kadane
        int a = nums[0],b = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            a = max(nums[i],a + nums[i]);
            b = max(a,b);
        }
        return b;
    }
};