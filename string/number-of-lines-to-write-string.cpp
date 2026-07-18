class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < widths.size(); i++) {
            mp['a' + i] = widths[i];
        }
        int lines = 1, width = 0;
        for (char c : s) {
            if (width + mp[c] > 100) {
                lines++;
                width = mp[c]; // when exceeded set to next character pixel
            } else {
                width += mp[c];
            }
        }
        return {lines, width};
    }
};