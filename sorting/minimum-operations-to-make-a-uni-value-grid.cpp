class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        // to median
        int target = arr[arr.size() / 2];
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            // if remainders are different
            if ((arr[i] % x) != (target % x)) {
                return -1;
            } else {
                // no of opns to make them equal
                count += abs(arr[i] - target) / x;
            }
        }
        return count;
    }
};