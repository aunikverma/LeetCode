class Solution {
public:
    vector<int> segmentTree;
    int n = 50000;

    // update
    void updateSegtree(int ind, int val, int i, int l, int r) {
        if (l == r) {
            segmentTree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (ind <= mid) {
            updateSegtree(ind, val, 2 * i + 1, l, mid);
        } else {
            updateSegtree(ind, val, 2 * i + 2, mid + 1, r);
        }
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    int querySegtree(int start, int end, int i, int l, int r) {
        // out of range
        if (l > end || r < start) {
            return 0;
        }
        if (l >= start && r <= end) {
            return segmentTree[i];
        }
        int mid = l + (r - l) / 2;
        return max(querySegtree(start, end, 2 * i + 1, l, mid),
                   querySegtree(start, end, 2 * i + 2, mid + 1, r));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        // segment tree size
        segmentTree.resize(4 * n, 0);

        // obstacles
        set<int> obstacles;
        obstacles.insert(0);

        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.upper_bound(x);
                int nxt = (it != obstacles.end() ? *it : -1);
                int p = *prev(it);

                // left tree(ind,val,root,left,right)
                updateSegtree(x, x - p, 0, 0, n - 1);
                // right side
                updateSegtree(nxt, nxt - x, 0, 0, n - 1);

                obstacles.insert(x);
            } else {
                int x = q[1];
                int block_size = q[2];

                auto it = obstacles.upper_bound(x);
                int p = *prev(it);

                int maxGap = querySegtree(0, p, 0, 0, n - 1);
                int best = max(maxGap, x - p);

                ans.push_back(best >= block_size);
            }
        }
        return ans;
    }
};