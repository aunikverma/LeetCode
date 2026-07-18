class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            unordered_map<int, int> mp1;
            for (int j = i + 1; j < n; j++) {
                mp1[nums[j]]++;
            }
            int res = ((int)mp.size() - (int)mp1.size());
            ans.push_back(res);
        }
        return ans;
    }
};