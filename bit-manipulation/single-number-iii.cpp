class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i : nums) {
            mp[i]++;
        }
        for (auto& v : mp) {
            if (v.second == 1) {
                ans.push_back(v.first);
            } else if (ans.size() == 2) {
                break;
            }
        }
        return ans;
    }
};