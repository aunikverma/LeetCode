class Solution {
public:
    int maxDifference(string s) {
        vector<int> l(26, 0);
        for (char i : s) {
            l[i - 'a']++;
        }
        vector<int> even;
        int o = INT_MIN;
        int ans = INT_MIN;
        for (int i : l) {
            if (i > 0 && i % 2 == 0) {
                even.push_back(i);
            } else {
                o = max(o, i);
            }
        }
        for (int i : even) {
            ans = max(ans, o - i);
        }
        return ans;
    }
};