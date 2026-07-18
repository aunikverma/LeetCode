struct Comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // return true if 'a' has lower priority than 'b'
        if (a.first == b.first)
            return a.second >
                   b.second;      // if equal count, smaller row index first
        return a.first < b.first; // bigger count first
    }
};
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        unordered_map<int, int> mp; // row and count of ones
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1)
                    count++;
            }
            mp[i] = count;
        }
        vector<int> ans(2, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        int maxi = INT_MIN;
        for (auto& v : mp) {
            pq.push({v.second, v.first});
        }
        ans[0] = pq.top().second;
        ans[1] = pq.top().first;
        return ans;
    }
};