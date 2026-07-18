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
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;
        getallsubsets(nums, ans, 0, allsubsets);
        int sum = 0;
        for (int i = 0; i < allsubsets.size(); i++) {
            int a = 0;
            for (int j = 0; j < allsubsets[i].size(); j++) {
                a ^= allsubsets[i][j];
            }
            sum += a;
        }
        return sum;
    }
};
