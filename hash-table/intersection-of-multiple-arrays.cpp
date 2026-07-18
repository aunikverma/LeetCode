class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> ans;
        for (auto i : nums) {
            for (auto j : i) {
                mp[j]++;
            }
        }
        for (auto& v : mp) {
            if (v.second == n) {
                ans.push_back(v.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};