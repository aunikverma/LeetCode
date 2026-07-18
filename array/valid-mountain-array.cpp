class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size() - 1;
        if (n < 2) {
            return false;
        }
        int r = n, l = 0;
        while (l + 1 < n && arr[l] < arr[l + 1]) {
            l += 1; // from start
        }
        while (r - 1 > 0 && arr[r] < arr[r - 1]) {
            r -= 1; // from end
        }
        return (l == r);
    }
};