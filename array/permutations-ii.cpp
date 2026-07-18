class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums); // adding smallest permutation
        while (next_permutation(nums.begin(),nums.end())) // it returns next permuttation
        {
            ans.push_back(nums);
        }
        return ans;
    }
};