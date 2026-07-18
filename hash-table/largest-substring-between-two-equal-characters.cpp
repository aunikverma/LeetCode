class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, pair<int, int>> mp; // first and last index
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]].first = INT_MAX;
                mp[s[i]].second = INT_MIN;
            }
            mp[s[i]].first = min(mp[s[i]].first, i);
            mp[s[i]].second = max(mp[s[i]].second, i);
        }
        int max_length = -1;
        for (auto& v : mp) {
            auto& [f, l] = v.second;
            if (f != l) {
                max_length = max(max_length, l - f - 1);
            }
        }
        return max_length;
    }
};