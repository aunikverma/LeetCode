// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n;
        if (n == 1) {
            return 1;
        }
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isBadVersion(mid) == true && isBadVersion(mid - 1) == false) {
                return mid;
            } else if (isBadVersion(mid) == true) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return 0;
    }
};