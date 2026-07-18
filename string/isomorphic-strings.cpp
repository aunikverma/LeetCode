class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end()) { // if there then check index,if not then add
                mp[s[i]] = i;
            }
            if (mp1.find(t[i]) == mp1.end()) {
                mp1[t[i]] = i;
            }
            if (mp[s[i]] != mp1[t[i]]) {
                return false; // if index not matches return false
            }
        }
        return true;
    }
};