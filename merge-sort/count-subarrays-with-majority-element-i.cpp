class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        // currsum-> count
        unordered_map<int, int> mp;

        int curr_sum = 0;
        mp[0] = 1;

        int validleftpoints = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                validleftpoints += mp[curr_sum];
                curr_sum += 1;
            } else {
                curr_sum -= 1;
                validleftpoints -= mp[curr_sum];
            }
            mp[curr_sum] += 1;
            ans += validleftpoints;
        }
        return ans;
    }
};