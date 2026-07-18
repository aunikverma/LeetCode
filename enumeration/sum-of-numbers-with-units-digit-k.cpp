class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0)
            return num;
        for (int i = 1; i <= 10; i++) {//since k <= 9
            if (i * k % 10 == num % 10 && i * k <= num) {
                return i;
            }
        }
        // 9 * 1 = 9
        // 9 * 11 = 99
        // 9 * 2 = 18
        // 9 * 12 = 108
        // 9 * 3 = 27
        // 9 * 13 = 117
        return -1;
    }
};