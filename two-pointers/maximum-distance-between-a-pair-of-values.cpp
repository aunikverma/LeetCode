class Solution {
public:
    // since decreasing
    // finding farthest ind where nums1[i] > nums2[j]
    int find_ind(vector<int>& nums2, int i, int j, int val) {
        int ans = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums2[mid] >= val) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums2.size();
        for (int i = 0; i < nums1.size(); i++) {
            int ind = find_ind(nums2, i, n - 1, nums1[i]);
            if (ind != -1) {
                ans = max(ans, abs(i - ind));
            }
        }
        return ans;
    }
};