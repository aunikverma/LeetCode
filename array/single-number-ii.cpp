class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        for (auto& v : mp) {
            if (v.second == 1) {
                return v.first;
            }
        }
        return 0;
    }
};