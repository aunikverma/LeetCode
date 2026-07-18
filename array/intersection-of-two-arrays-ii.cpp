class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int>ans;
        for (int i : nums1) {
            mp[i]++; // copying frquency of nums1
        }
        for (int i : nums2) {
            if (mp[i] > 0) {
                ans.push_back(i);
                mp[i]--;
            }
        }
        return ans;
    }
};