class Solution {
public:
    int getSum(int a, int b) {
        while(b=(~(a ^= b)&b) << 1);
        return a;
    }
};