class Solution {
public:
    string freqAlphabets(string s) {
        unordered_map<string, char> mp;
        string ans = "";
        char c = 'a';
        for (int i = 1; i <= 26; i++) {
            mp[to_string(i)] = c++;
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            string a = "";
            if (s[i] == '#') {
                a += s[i - 2];
                a += s[i - 1];
                ans += mp[a];
                i -= 2;
            } else {
                a += s[i];
                ans += mp[a];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};