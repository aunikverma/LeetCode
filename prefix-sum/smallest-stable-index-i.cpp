class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        map<int, int> mp;
        for (int i : nums) {
            mp[i] += 1;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            // curr max
            maxi = max(maxi, nums[i]);
            auto it = mp.begin();
            int mini = it->first;
            // smallest index
            if ((maxi - mini) <= k) {
                return i;
            }
            // removing nums[i]
            mp[nums[i]] -= 1;
            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
        }
        return -1;
    }
};