class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        vector<int> a(s.begin(), s.end());
        reverse(a.begin(), a.end());
        if (k > a.size()) {
            return a;
        }
        return {a.begin(), a.begin() + k};
    }
};