class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(int i : nums)
        {
            mp[i]++;
        }
        for(auto &v : mp)
        {
            if(v.second == 2)
            {
                res.push_back(v.first);
            }
        }
        return res;
    }
};