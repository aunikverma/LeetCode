class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        set<int> s1;
        for (auto& v : mp) {
            s1.insert(v.second);
        }
        if (s1.size() > 1) return false;
        return true;
    }
};