class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        // Binary search to find the index where missing(i) >= k
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
        // At this point, `low` is the first index where missing(low) >= k
        // If no such index, the k-th missing number lies beyond the array
        return low + k;
    }
};
