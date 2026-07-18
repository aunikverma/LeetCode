class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0; // base case
        }
        int k = 0;
        while (1 << k <= n) { //2^k <= n
            k++;
        }
        k--;
        return ((1 << (k + 1)) - 1 - minimumOneBitOperations(1 << k ^ n)); //2^k+1 - 1 -(2^k ^ n);
    }
};
// we have to return the no of operations to make the no zero
// we can reverse the unit bit to 1 - 0 and  0 - 1 in one operation
// or we can reverse the bit if i + 1 bit is 1 and i + 2 to n bits are 0
// 1000 to 0100 take 8 steps 2^k - 1