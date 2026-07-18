class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        auto Comp = [](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            } else {
                return a[0] > b[0];
            }
        };
        sort(intervals.begin(), intervals.end(), Comp);
        int second = -1, first = -1, ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if (l <= first) {
                continue;
            }
            if (l > second) {
                ans += 2;
                second = r;
                first = r - 1;
            } else {
                ans++;
                first = second;
                second = r;
            }
        }
        return ans;
    }
};
// if your [l,r] then r,r - 1 are most optimal selections