class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        if (k == 1)
            return {arr[0], arr[arr.size() - 1]};
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq; // max heap
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double div = (double)arr[i] / arr[j];
                if (pq.empty() || pq.size() < k) {
                    pq.push({div, {arr[i], arr[j]}});
                } else if (div < pq.top().first) {
                    pq.pop();
                    pq.push({div, {arr[i], arr[j]}});
                }
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};