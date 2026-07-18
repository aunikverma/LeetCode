class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        set<int>s1;
        for(int i:arr)
        {
            mp[i]++;
        }
        int m = mp.size();
        for(auto &v:mp)
        {
            s1.insert(v.second);
        }
        int c = s1.size();
        if(m == c)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};