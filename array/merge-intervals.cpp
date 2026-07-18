class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[0] < b[0]);
             });
        vector<vector<int>> merged;
        vector<int> prev = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            vector<int> interval = arr[i];
            if (interval[0] <= prev[1]) {
                prev[1] = max(prev[1], interval[1]);
            } else {
                merged.push_back(prev);
                prev = interval;
            }
        }
        merged.push_back(prev);
        return merged;
    }
};