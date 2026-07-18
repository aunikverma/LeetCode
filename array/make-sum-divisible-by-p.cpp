class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum % p == 0) {
            return 0;
        }
        int target = sum % p;
        unordered_map<int, int> mp; // prev sum % p
        int curr = 0;
        mp[0] = -1;
        int ans = nums.size();
        for (int j = 0; j < nums.size(); j++) {
            curr = (curr + nums[j]) % p;
            int f = (curr - target + p) % p;
            if (mp.find(f) != mp.end()) {
                ans = min(ans, j - mp[f]);
            }
            mp[curr] = j;
        }
        return (ans == nums.size()) ? -1 : ans; //since removing whole array is not allowed
    }
};