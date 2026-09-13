class Solution {
public:
    int n;
    struct Node {
        long long score = 0;
        vector<int> inds;
    };
    vector<int> nextInd;
    vector<vector<Node>> t;

    int findNext(vector<vector<int>>& intervals, int r) {
        int l = 0, h = n - 1;
        int result = n;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (intervals[mid][0] > r) {
                result = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        // added index to map
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        // sorted using start point
        sort(intervals.begin(), intervals.end());
        nextInd.resize(n);

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            nextInd[i] = findNext(intervals, end);
        }
        int k = 4;
        t.assign(n + 1, vector<Node>(k + 1));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 4; k >= 0; k--) {
                if (k == 0) {
                    continue;
                }
                int wt = intervals[i][2];
                int ind = intervals[i][3];
                int j = nextInd[i];

                Node skip = t[i + 1][k];
                Node temp = t[j][k - 1];

                Node take;
                take.score = temp.score + wt;
                take.inds = temp.inds;
                take.inds.push_back(ind);
                sort(take.inds.begin(), take.inds.end());

                Node result;
                if (skip.score > take.score) {
                    result = skip;
                } else if (skip.score < take.score) {
                    result = take;
                } else {
                    result = (skip.inds < take.inds ? skip : take);
                }
                t[i][k] = result;
            }
        }
        return t[0][4].inds;
    }
};
// we have to return the lexicographically smallest array of atmost
// 4 indexes comprising of non overlapping intervals
// have maximum weights

// sort intervals
// use binary search to find next optimal interval
