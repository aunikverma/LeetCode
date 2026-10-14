class Solution {
private:
    // Function to find the peak element's index using the MountainArray API
    int peak(MountainArray& arr) {
        int i = 0;
        int j = arr.length() - 1;
        while (i < j) {
            int m = i + (j - i) / 2;
            if (arr.get(m) < arr.get(m + 1)) {
                i = m + 1;
            } else {
                j = m;
            }
        }
        return i; // Peak index
    }

    // Binary search function for ascending order
    int binA(MountainArray& arr, int s, int e, int k) {
        while (s <= e) {
            int m = s + (e - s) / 2;
            int val = arr.get(m);
            if (val == k) {
                return m;
            } else if (val > k) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return -1;
    }

    // Binary search function for descending order
    int binD(MountainArray& arr, int s, int e, int k) {
        while (s <= e) {
            int m = s + (e - s) / 2;
            int val = arr.get(m);
            if (val == k) {
                return m;
            } else if (val < k) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return -1;
    }

public:
    int findInMountainArray(int t, MountainArray& arr) {
        int p = peak(arr);            // Find peak index
        int ans = binA(arr, 0, p, t); // Search in ascending part
        if (ans != -1) {
            return ans;
        }
        return binD(arr, p + 1, arr.length() - 1,t); // Search in descending part
    }
};