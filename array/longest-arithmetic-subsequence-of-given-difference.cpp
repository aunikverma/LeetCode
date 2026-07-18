class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int temp_prev = arr[i] - difference;
            dp[arr[i]] = (dp.count(temp_prev) ? 1 + dp[temp_prev] : 1);
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};