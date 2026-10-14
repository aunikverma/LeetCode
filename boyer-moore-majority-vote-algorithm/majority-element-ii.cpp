class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int c = nums.size() / 3;
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        for (auto& v : mp) {
            if (v.second > c) {
                ans.push_back(v.first);
            }
        }
        return ans;
    }
};