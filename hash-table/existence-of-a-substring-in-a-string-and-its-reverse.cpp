class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_map<string, int> mp;
        unordered_map<string, int> mp1;
        for (int i = 0; i < s.length() - 1; i++) {
            string a = "";
            a += s[i];
            a += s[i + 1];
            if (mp.find(a) == mp.end()) {
                mp[a]++;
            }
        }
        for (int i = s.length() - 1; i >= 1; i--) {
            string a = "";
            a += s[i];
            a += s[i - 1];
            if (mp1.find(a) == mp1.end()) {
                mp1[a]++;
            }
        }
        for (auto& v : mp) {
            if (mp1[v.first] >= 1) {
                return true;
            }
        }
        return false;
    }
};