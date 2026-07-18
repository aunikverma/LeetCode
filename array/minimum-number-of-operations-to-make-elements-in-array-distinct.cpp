class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if (s.size() == nums.size())
            return 0; // all elements are distinct

        if (nums.size() <= 3)
            return 1; // removed all

        int ans = 0;
        int i = 3;
        while (i < nums.size()) {
            ans++;
            set<int> s(nums.begin() + i, nums.end());
            if (s.size() == nums.size() - i) {
                return ans;
            }
            if ((nums.size() - i) <= 3) {
                ans++;
                return ans;
            }
            i += 3;
        }
        return ans;
    }
};