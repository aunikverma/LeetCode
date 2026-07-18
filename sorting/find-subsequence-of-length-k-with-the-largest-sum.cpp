class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> p;
        for (int i = 0; i < nums.size(); i++) {
            p.push_back({nums[i], i});
        }
        sort(p.rbegin(), p.rend());
        vector<pair<int, int>> p1;
        for (int i = 0; i < k; i++) {
            p1.push_back({p[i].second, p[i].first});
        }
        sort(p1.begin(), p1.end());
        vector<int> ans;
        for (auto& i : p1) {
            ans.push_back(i.second);
        }
        return ans;
    }
};