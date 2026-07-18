class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int, int>> p;
        for (int i : nums) {
            mp[i]++;
        }
        for (auto& v : mp) {
            p.push_back({v.second, v.first});
        }
        sort(p.rbegin(), p.rend());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(p[i].second);
        }
        return ans;
    }
};