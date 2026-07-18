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
        getallsubsets(nums, ans, st + 1, allsubsets);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int>ans;//to store every subset ans adding it to all subsets
        getallsubsets(nums, ans, 0, allsubsets);
        return allsubsets;
    }
};