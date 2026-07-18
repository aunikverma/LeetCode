class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int m = INT_MAX; // minimum absolute difference
        for (int i = 0; i + 1 < arr.size(); i++) {
            int c = abs(arr[i + 1] - arr[i]);
            m = min(m, c);
        }
        vector<int> b(2, 0);
        for (int i = 0; i + 1 < arr.size(); i++) {
            int c = abs(arr[i + 1] - arr[i]);
            if (c == m) {
                b[0] = arr[i];
                b[1] = arr[i + 1];
                ans.push_back(b);
            }
        }
        return ans;
    }
};