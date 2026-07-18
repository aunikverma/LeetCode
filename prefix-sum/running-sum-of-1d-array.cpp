class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans(nums.size());
        partial_sum(begin(nums),end(nums),begin(ans));//insert prefix sum
        return ans;
    }
};