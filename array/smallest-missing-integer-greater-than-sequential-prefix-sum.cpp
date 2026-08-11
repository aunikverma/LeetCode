class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i] += 1;
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        while (mp.find(sum) != mp.end()) {
            sum += 1;
        }
        return sum;
    }
};