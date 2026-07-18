class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& arr,vector<vector<int>>& arr1) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < arr.size() && j < arr1.size()) {
            int low = max(arr[i][0], arr1[j][0]);  // start of intersection
            int high = min(arr[i][1], arr1[j][1]); // end of intersection
            if (low <= high) {
                ans.push_back({low, high});
            }
            if (arr[i][1] < arr1[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};