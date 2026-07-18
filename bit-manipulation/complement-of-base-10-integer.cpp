class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int m = n, mask = 0;
        while (m > 0) {
            mask = (mask << 1) | 1;
            m >>= 1;
        }
        return (mask ^ n);
    }
};
// similar all set bits and xor to get flips