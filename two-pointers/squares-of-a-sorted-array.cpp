class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        vector<int> ans(a.size());
        int k = a.size() - 1;
        int st = 0, e = a.size() - 1;
        while (st <= e) {
            if (a[st] * a[st] > a[e] * a[e]) {
                ans[k] = a[st] * a[st];
                st++;
            } else {
                ans[k] = a[e] * a[e];
                e--;
            }
            k--;
        }
        return ans;
    }
};