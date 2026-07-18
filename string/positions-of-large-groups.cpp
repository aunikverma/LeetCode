class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == s[i + 1]) {
                int count = 1,x = i;
                while (i + 1 < s.length() && s[i] == s[i + 1]) {
                    i++;
                    count++;
                }
                if (count >= 3) {
                    ans.push_back({x, i});
                }
            }
        }
        return ans;
    }
};