class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(int i = 0;i < s.length();i++)
        {
            mp[s[i]]++;
        }
        for(int i = 0;i < t.length();i++)
        {
            if(mp.find(t[i]) == mp.end() || mp[t[i]] == 0)
            {
                return t[i];
            }
            else
            {
                --mp[t[i]];
            }
        }
        return 0;
    }
};