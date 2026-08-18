class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i] += 1;
        }
        int ans;
        // largest which occurs only once
        if (k == 1) {
            ans = -1;
            for (auto& v : mp) {
                if (v.second == 1) {
                    ans = max(ans, v.first);
                }
            }
        } else if (k > 1 && k < n) {
            // either nums[0] or  nums[n - 1]
            if (mp[nums[0]] == mp[nums[n - 1]]) {
                ans = max(nums[0], nums[n - 1]);
            } else if (mp[nums[0]] > mp[nums[n - 1]]) {
                ans = nums[n - 1];
            } else {
                ans = nums[0];
            }
        } else if (k == n) {
            // largest in whole nums
            ans = -1;
            for (auto& v : mp) {
                ans = max(ans, v.first);
            }
        }
        return ans;
    }
};