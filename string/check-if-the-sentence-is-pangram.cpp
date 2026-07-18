class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_map<char,int>mp;
        for(char c : s)
        {
            mp[c]++;
        }
        if(mp.size() < 26) return false;
        return true;
    }
};