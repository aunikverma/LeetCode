class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        for (auto& v : mp) {
            if (v.second > 1) {
                return true;
            }
        }
        return false;
    }
};