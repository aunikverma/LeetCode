class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i] += 1;
        }
        int ans = -1;
                  // largest which occurs only once
                  if (k == 1) {
            for (auto& v : mp) {
                if (v.second == 1) {
                    ans = max(ans, v.first);
                }
            }
        }
        else if (k == n) {
            // largest in whole nums
            for (auto& v : mp) {
                ans = max(ans, v.first);
            }
        }
        else {
            // either nums[0] or  nums[n - 1]
            if (mp[nums[0]] == 1 && mp[nums[n - 1]] == 1) {
                ans = max(nums[0], nums[n - 1]);
            } else if (mp[nums[0]] == 1) {
                ans = nums[0];
            } else if (mp[nums[n - 1]] == 1) {
                ans = nums[n - 1];
            }
        }
        return ans;
    }
};