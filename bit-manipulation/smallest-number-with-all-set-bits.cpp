class Solution {
private:
    int bits(int n) {
        int c = 0;
        while (n > 0) {
            c++;
            n >>= 1;
        }
        return c;
    }

public:
    int smallestNumber(int n) {
        int a = bits(n);
        return (pow(2, a) - 1);
    }
};