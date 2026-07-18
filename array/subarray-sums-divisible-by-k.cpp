class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int c = 0;
        int curr_sum = 0; // running sum
        unordered_map<int, int> mp;
        mp[0] = 1; // for empty subarray
        for (int i : nums) {
            curr_sum += i;
            int r = (curr_sum % k + k) % k;
            if (mp.find(r) != mp.end()) {
                c += mp[r];
            }
            if (mp.find(r) == mp.end()) {
                mp[r] = 1;
            } else {
                mp[r]++;
            }
        }
        return c;
    }
};