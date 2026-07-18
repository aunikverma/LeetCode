class Solution {
private:
    int bin(vector<int>& arr, int s, int e, int k) {
        if (s > e)
            return -1;
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
            return mid;
        if (arr[mid] > k) {
            return bin(arr, 0, mid - 1, k);
        } else {
            return bin(arr, mid + 1, e, k);
        }
    }

public:
    int search(vector<int>& arr, int target) {
        return bin(arr, 0, arr.size() - 1, target);
    }
};