class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        for (auto& v : mp) {
            if (v.second > 2) {
                return false;
            }
        }
        return true;
    }
};