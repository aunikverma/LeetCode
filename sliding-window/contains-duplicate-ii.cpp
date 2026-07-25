class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& s, int k) {
        // base case
        if (k <= 0 || s.size() <= 1) {
            return false;
        }
        int left = 0;
        unordered_map<int, int> mp;

        for (int right = 0; right < s.size(); right++) {
            mp[s[right]] += 1;
            if (mp[s[right]] > 1) {
                while (mp[s[right]] > 1) {
                    if (abs(right - left) <= k) {
                        return true;
                    }
                    mp[s[left]] -= 1;
                    left += 1;
                }
            }
        }
        return false;
    }
};