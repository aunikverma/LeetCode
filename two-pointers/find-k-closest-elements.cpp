class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0,
            right = arr.size() - k; // The last possible starting index is arr.size() - k.
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1; // means the leftmost element is farther from
                // x than the element just to the right of the window.
            } else {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
