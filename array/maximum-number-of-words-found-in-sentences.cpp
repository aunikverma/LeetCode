class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int r = INT_MIN;
        for (auto& v : sentences) {
            int s = 1; // no of spaces
            for (char c : v) {
                if (c == ' ') {
                    s++;
                }
            }
            r = max(r, s);
        }
        return r;
    }
};