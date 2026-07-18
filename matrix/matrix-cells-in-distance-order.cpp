class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                          int cCenter) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>>
            pq; // can store duplicate values
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << i << " " << j << endl;
                int dis = abs(rCenter - i) + abs(cCenter - j);
                pq.push({dis, {i, j}});
            }
        }
        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};