#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

class Solution {
public:
    bool isAnagram(string s, string t) {
        fast;
        vector<int>mp1(26),mp2(26);
        for(auto&c:s)
        {
            ++mp1[c-'a'];
        }
        for(auto&c:t)
        {
            ++mp2[c-'a'];
        }
        for(int i = 0; i < 26; ++i){
            if(mp1[i] != mp2[i])
            {
                return false;
            }
        }
        return true;
    }
};
