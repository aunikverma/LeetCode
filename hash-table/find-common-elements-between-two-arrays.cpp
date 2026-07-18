class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        unordered_map<int, int> mp1;
        vector<int> ans;
        for (int i : nums1) {
            mp[i]++;
        }

        for (int i : nums2) {
            mp1[i]++;
        }

        int c = 0, c1 = 0;

        for (int i : nums1) {
            if (mp1.find(i) != mp1.end()) {
                c++;
            }
        }

        for (int i : nums2) {
            if (mp.find(i) != mp.end()) {
                c1++;
            }
        }
        ans.push_back(c);
        ans.push_back(c1);
        
        return ans;
    }
};