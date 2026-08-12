class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int longest = 1;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // add in map
            int val = nums[right];
            mp[val] += 1;
            // if freq is greater
            while (mp[val] > k) {
                mp[nums[left]] -= 1;
                left++;
            }
            // update maximum
            longest = max(longest, (right - left + 1));
        }
        return longest;
    }
};