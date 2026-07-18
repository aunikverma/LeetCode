class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> mp(26, 0);
        for (auto& w : words) {
            for (char c : w) {
                mp[c - 'a'] += 1;
            }
        }
        for (int i : mp) {
            if (i % words.size() != 0) {
                return false;
            }
        }
        return true;
    }
};