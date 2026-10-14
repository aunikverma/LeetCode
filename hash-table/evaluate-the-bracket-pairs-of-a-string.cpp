class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& i : knowledge) {
            mp[i[0]] = i[1];
        }
        string ans = "";
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                string key = "";
                i++;
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
            } else {
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};