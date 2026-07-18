class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<pair<int, pair<int, int>>> A(50000, {0, {-1, -1}}); //storing each value frequency and first and last index
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int e = nums[i];
            if (A[e].first == 0) {
                A[e].first = 1;
                A[e].second.first = i;
                A[e].second.second = i;
            } else {
                A[e].first++;
                A[e].second.second = i;
            }
            mp[e]++;
        }
        // map
        int maxi = INT_MIN;
        for (auto& v : mp) {
            maxi = max(maxi, v.second); //finding largest degree
        }
        int x = INT_MAX;
        for (auto& v : mp) {
            if (v.second == maxi) {
                int d = //then min subarray
                    (A[v.first].second.second - A[v.first].second.first) + 1;
                x = min(x, d);
            }
        }
        return x;
    }
};