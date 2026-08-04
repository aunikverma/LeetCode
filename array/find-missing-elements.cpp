class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        vector<int> mp(101, 0);
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i : nums) {
            mp[i - 1]++;
            mini = min(mini, i);
            maxi = max(i, maxi);
        }
        for (int i = mini + 1; i < maxi; i++) {
            if (mp[i - 1] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};