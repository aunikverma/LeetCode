class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> mp;
        string w = ""; // word
        for (char c : paragraph) {
            if (isalpha(c)) {
                w += tolower(c);
            } else if (!w.empty()) // if word not empty
            {                      // and not in ban
                if (!ban.count(w))
                     { mp[w]++; }
                w = "";
            }
        }
        if (!w.empty() && !ban.count(w)) { // adding last word
            mp[w]++;
        }
        string ans = "";
        int c = INT_MIN;
        for (auto& v : mp) {
            if (v.second > c) {
                c = v.second;
                ans = v.first;
            }
        }
        return ans;
    }
};