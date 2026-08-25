class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        int i = 1;
        while (mp.find(k * i) != mp.end()) {
            i += 1;
        }
        return (k * i);
    }
};