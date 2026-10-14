class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> pq; // dis : points index
        for (int i = 0; i < points.size(); i++) {
            long long a = 1LL * points[i][0] * points[i][0] +
                          1LL * points[i][1] * points[i][1];
            pq.push({a, i});
            if (pq.size() > k) {
                pq.pop(); // only k
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto i = pq.top();
            pq.pop();
            ans.push_back(points[i.second]); // whole points
        }
        return ans;
    }
};