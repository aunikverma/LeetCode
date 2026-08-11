class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i] += 1;
        }
        int maxi = INT_MIN;
        int i = 1;
        while (i < n) {
            if (nums[i] == nums[i - 1] + 1) {
                int sum = nums[i - 1];
                while (i < n && (nums[i - 1] + 1) == nums[i]) {
                    sum += nums[i];
                    i++;
                }
                maxi = max(maxi, sum);
            } else {
                i++;
            }
        }
        while (mp.find(maxi) != mp.end()) {
            maxi += 1;
        }
        return maxi;
    }
};