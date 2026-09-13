class Solution {
public:
    int n;
    struct Node {
        long long score = -1;
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

    Node solve(vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n) {
            return Node();
        }

        if (t[i][k].score != -1) {
            return t[i][k];
        }

        int wt = intervals[i][2];
        int ind = intervals[i][3];
        int j = nextInd[i];

        Node skip = solve(intervals, i + 1, k);
        Node temp = solve(intervals, j, k - 1);

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
        return t[i][k] = result;
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
        return solve(intervals, 0, k).inds;
    }
};
// we have to return the lexicographically smallest array of atmost
// 4 indexes comprising of non overlapping intervals
// have maximum weights

// sort intervals
// use binary search to find next optimal interval
