class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int count = 0, maxi = 0;
        while (n > 0) {
            if (n & 1) {
                if (prev != -1) {
                    maxi = max(maxi, count - prev);
                }
                prev = count;
            }
            count++;
            n >>= 1;
        }
        return maxi;
    }
};