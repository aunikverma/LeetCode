class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size() - 1;
        int j = nums2.size() - 1;
        nums1.resize(nums1.size() + nums2.size());
        int k = nums1.size() - 1;
        while (i >= 0 && j >= 0) {
            if (nums2[j] > nums1[i]) {
                nums1[k] = nums2[j];
                k--;
                j--;
            } else {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        while (i >= 0) {
            nums1[k] = nums1[i];
            k--;
            i--;
        }
        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        int mid = (nums1.size() - 1) / 2;
        if (nums1.size() & 1) {
            return (nums1[mid] / 1.0000);
        } else {
            return ((nums1[mid] + nums1[mid + 1]) / 2.0000);
        }
        return 0;
    }
};