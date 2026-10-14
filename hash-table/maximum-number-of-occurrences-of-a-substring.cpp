class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();

        unordered_map<string, int> count;
        unordered_map<char, int> mp;

        int l = 0;

        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            while ((r - l + 1) > minSize || mp.size() > maxLetters) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            if ((r - l + 1) == minSize) {
                count[s.substr(l, r - l + 1)]++;
            }
        }

        int ans = 0;
        for (auto& v : count) {
            ans = max(ans, v.second);
        }
        return ans;
    }
};
// if substring having size greater than minSize
// appear max time then smaller substring of size minSize also appear same time
// therefore we only have to check minSize substring