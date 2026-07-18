class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int a = __builtin_popcount(num1);//no of set bits in num 1
        int b = __builtin_popcount(num2);//no of set bits in num 2
        int res = num1;
        for (int i = 0; i < 32; ++i) {
            if (a > b && ((1 << i) & num1)) {//if a has too many bits
                res ^= 1 << i;//reverse to make it 0, and decrement a
                --a;
            }
            if (a < b && !((1 << i) & num1)) {//if a has less set bits than b
                res ^= 1 << i;//reverse to make it 1, and increment a
                ++a;
            }
        }
        return res;
    }
};