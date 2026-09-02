class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even = 0, odd = 0;
        for (int i : nums1) {
            if (i & 1) {
                odd += 1;
            } else {
                even += 1;
            }
        }
        return (odd == n || even == n || odd == even);
    }
};