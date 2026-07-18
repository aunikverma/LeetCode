class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        map<pair<char, int>, int> mp;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i]; // starting character
            int l = 0;      // length of substring
            for (int j = i; j < s.length(); j++) {
                if (ch == s[j]) {
                    l++;
                    mp[{ch, l}]++;
                } else {
                    break;
                }
            }
        }
        for (auto& v : mp) {
            int len = v.first.second; // if occurence greater than equal 3 then
                                      // change ans
            if (v.second >= 3) {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};