class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i] += 1;
        }
        int ans;
        if (k == 1 || k == n) {
            ans = -1;
            for (auto& v : mp) {
                if (v.second == 1) {
                    ans = max(ans, v.first);
                }
            }
        } else if (k > 1 && k < n) {
            if (mp[nums[0]] == mp[nums[n - 1]]) {
                ans = max(nums[0], nums[n - 1]);
            } else if (mp[nums[0]] > mp[nums[n - 1]]) {
                ans = nums[n - 1];
            } else {
                ans = nums[0];
            }
        }
        return ans;
    }
};