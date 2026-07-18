class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int a = 0;
        int maxi = INT_MIN;
        for (int i : nums) {
            a += i;
            maxi = max(maxi, i);
            mp[i]++;
        }
        if (maxi < 0)
            return maxi; // if maximum element is less than zero
        int ans = 0;
        for (auto& v : mp) {
            if (v.first > 0) {
                ans += v.first;
            }
        }
        return ans;
    }
};