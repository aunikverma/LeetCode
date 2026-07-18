class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(s.size());
        int pos = -n;//far away vlaue
        for (int i = 0; i < n; i++) {
            if (s[i] == c)
                pos = i;
            ans[i] = i - pos;
        }
        pos = 2*n;//far value
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c)
                pos = i;
            ans[i] = min(ans[i], pos - i);
        }
        return ans;
    }
};
