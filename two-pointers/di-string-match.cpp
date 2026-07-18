class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length() + 1;
        vector<int> ans(n, 0);
        int i = 0, j = n - 1, k = 0;
        while (k <= s.length()) {
            char c = (k < s.length()) ? s[k] : s[n - 1];
            if (c == 'I') { // i means increasing
                ans[k] = i;
                i++;
            } else { // decreasing
                ans[k] = j;
                j--;
            }
            k++;
        }
        return ans;
    }
};