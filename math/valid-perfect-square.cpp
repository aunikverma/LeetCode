class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        int s = 1;
        int e = num / 2;
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long a = mid * mid;
            if (a == num) {
                return true;
            } else if (a > num) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return false;
    }
};