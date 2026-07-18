class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if (mp.find(c) != mp.end() && i != mp[c]) {
                return {mp[c], i};
            }
        }

        return {};
    }
};