class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>mp;
        for(int i : nums) mp[i]++;
        while(mp.find(original) != mp.end()){
            original <<= 1;
        }
        return original;
    }
};