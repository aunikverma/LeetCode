class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp(26, 0);
        for (char c : chars) {
            mp[c - 'a']++;
        }
        int ans = 0;
        for (auto w : words) {
            vector<int> mp1(26, 0);
            for (char c : w) {
                mp1[c - 'a']++;
            }
            bool v = true;
            for (int i = 0; i < 26; i++) {
                if (mp[i] < mp1[i]) {
                    v = false;
                }
            }
            if (v) {
                ans += w.length();
            }
        }
        return ans;
    }
};