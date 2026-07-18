class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        mp['b'] = 0;
        mp['a'] = 0;
        mp['l'] = 0;
        mp['o'] = 0;
        mp['n'] = 0;
        for (char c : text) {
            if (mp.count(c)) {
                mp[c] += 1;
            }
        }
        int count = INT_MAX;
        for (auto& v : mp) {
            if (v.first == 'l' || v.first == 'o') {
                count = min(count, v.second >> 1);
            } else {
                count = min(count, v.second);
            }
        }
        return count;
    }
};