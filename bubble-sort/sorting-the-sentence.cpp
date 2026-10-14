class Solution {
public:
    string sortSentence(string s) {
        map<int, string> mp;
        string ans = "";
        string a = "";
        for (char c : s) {
            if (c >= '1' && c <= '9') {
                mp[c - '0'] = a;
                a = "";
            } else if (c != ' ') {
                a += c;
            }
        }
        for (auto& v : mp) {
            ans += v.second + ' ';
        }
        return ans.substr(0,ans.size() - 1);
    }
};