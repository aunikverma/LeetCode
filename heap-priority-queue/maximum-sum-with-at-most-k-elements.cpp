class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < grid.size(); i++) {
            priority_queue<int, vector<int>, greater<int>> p;
            for (int j = 0; j < grid[0].size(); j++) {
                p.push(grid[i][j]);
                if (p.size() > limits[i]) {
                    p.pop();
                }
            }
            while (!p.empty()) {
                pq.push(p.top());
                p.pop();
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};