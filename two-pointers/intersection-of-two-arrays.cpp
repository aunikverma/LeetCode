class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;//unique elements
        set<int> s(nums1.begin(), nums1.end());
        for (int i : nums2) {
            if (s.find(i) != s.end()) {
                s1.insert(i);
            }
        }
        vector<int> ans(s1.begin(), s1.end());
        return ans;
    }
};