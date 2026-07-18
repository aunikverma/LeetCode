class Solution {
private:
    void permutations(vector<int>nums,int st,vector<vector<int>>& ans)
    {
        if(st == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i = st;i < nums.size();i++)
        {
            swap(nums[st],nums[i]);
            permutations(nums,st + 1,ans);
            //backtrack
            swap(nums[st],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutations(nums,0,ans);
        return ans;
    }
};