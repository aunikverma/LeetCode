class Solution {
private:
    void getallsubsets(vector<int>& nums, vector<int>& ans, int st,vector<vector<int>>& allsubsets) {
        if (st == nums.size()) {
            allsubsets.push_back({ans}); // adding it to the all subsets
            return;
        }
        // inclusion
        ans.push_back(nums[st]);
        getallsubsets(nums, ans, st + 1, allsubsets);

        // backtrack
        ans.pop_back();

        // exclusion
        int ind = st + 1;//index
        while(ind < nums.size() && nums[ind] == nums[ind - 1])
        {
            ind++;
        }
        getallsubsets(nums, ans, ind, allsubsets);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<vector<int>>allsubsets;
        getallsubsets(nums,ans,0,allsubsets);
        return allsubsets;
    }
};