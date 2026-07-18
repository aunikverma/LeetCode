class Solution {
public:
    int find_near(vector<int>& v, int q, int n) {
        int pos = lower_bound(v.begin(), v.end(), q) - v.begin();
        int res = INT_MAX;
        // left neighbor (wrap-around)
        int l = v[(pos - 1 + v.size()) % v.size()];
        if (l != q) {
            int d1 = abs(q - l);
            int d2 = n - d1;
            res = min(res, min(d1, d2));
        }
        // right neighbor (wrap-around)
        int r = v[(pos + 1) % v.size()];
        if (r != q) {
            int d1 = abs(q - r);
            int d2 = n - d1;
            res = min(res, min(d1, d2));
        }
        return res;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int a = nums[queries[i]];
            if (mp[a].size() < 2) {
                ans.push_back(-1);
            } else {
                int v = find_near(mp[a], queries[i], n);
                ans.push_back(v);
            }
        }
        return ans;
    }
};