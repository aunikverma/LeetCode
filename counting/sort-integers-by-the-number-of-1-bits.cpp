class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> arr1;

        for (int i : arr) {
            int c = __builtin_popcount(i);
            arr1.push_back({c, i});
        }

        sort(arr1.begin(), arr1.end());

        int k = 0;
        for (auto& v : arr1) {
            arr[k++] = v.second;
        }

        return arr;
    }
};