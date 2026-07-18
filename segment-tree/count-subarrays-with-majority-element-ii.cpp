class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        // currsum->count
        unordered_map<int, int> mp;
        int curr_sum = 0;
        mp[0] = 1;
        long long ans = 0, valid = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                valid += mp[curr_sum];
                curr_sum += 1;
            } else {
                curr_sum -= 1;
                valid -= mp[curr_sum];
            }
            mp[curr_sum] += 1;
            ans += valid;
        }
        return ans;
    }
};