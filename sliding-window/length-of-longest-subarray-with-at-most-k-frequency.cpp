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
            // if freq greater than k
            if (mp[val] > k) {
                int freq = mp[val];
                while (left < n && freq > k) {
                    mp[nums[left]] -= 1;
                    if (mp[nums[left]] == val) {
                        freq -= 1;
                    }
                    left++;
                }
            }
            longest = max(longest, (right - left + 1));
        }
        return longest;
    }
};