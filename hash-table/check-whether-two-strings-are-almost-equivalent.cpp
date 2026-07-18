class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> mp(26, 0);
        vector<int> mp1(26, 0);
        for (char c : word1) {
            mp[c - 'a'] += 1;
        }
        for (char c : word2) {
            mp1[c - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++) {
            if (abs(mp[i] - mp1[i]) >= 4) {
                return false;
            }
        }
        return true;
    }
};