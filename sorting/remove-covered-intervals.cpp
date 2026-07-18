class Solution {
public:
    bool static Comp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return (a[1] > b[1]);
        }
        return (a[0] < b[0]);
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort
        sort(intervals.begin(), intervals.end(), Comp);
        int n = intervals.size();
        auto prev = intervals[0];
        int count = 0;
        for (int i = 1; i < n; i++) {
            auto curr = intervals[i];
            int a = curr[0], b = curr[1];
            int c = prev[0], d = prev[1];

            if (c <= a && b <= d) {
                count += 1;
            } else {
                prev = curr;
            }
        }
        return (n - count);
    }
};