class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = g.size() - 1;
        int j = s.size() - 1;
        int ans = 0;
        while (i >= 0 && j >= 0) {
            if (s[j] < g[i]) {
                i--;
            } else if (s[j] >= g[i]) {
                j--;
                i--;
                ans++;
            }
        }
        return ans;
    }
};