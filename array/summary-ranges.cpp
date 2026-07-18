class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size(),i = 0;
        while (i < n) {
            int start = i;
            while (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
                i++;
            }
            if (i == start) {
                ans.push_back(to_string(nums[i]));
            } else {
                ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            }
            i++;
        }
        return ans;
    }
};