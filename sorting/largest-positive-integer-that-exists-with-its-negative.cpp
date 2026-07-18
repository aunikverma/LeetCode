class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        sort(nums.rbegin(), nums.rend());
        int ans = -1;
        for (int i : nums) {
            if (i >= 1 && s.find(-i) != s.end()) {
                ans = i;
                break;
            } else if (i < 0)
                break;
        }
        return ans;
    }
};