class Solution {
private:
    void words(unordered_map<string, int>& mp, string s) {
        string a = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                mp[a]++;
                a = "";
            } else if (i == s.length() - 1) {
                a += s[i];
                mp[a]++;
            } else {
                a += s[i];
            }
        }
    }

public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        words(mp, s1);
        words(mp, s2);
        vector<string> ans;
        for (auto& v : mp) {
            cout << v.first << " " << v.second << endl;
            if (v.second == 1) {
                ans.push_back(v.first);
            }
        }
        return ans;
    }
};