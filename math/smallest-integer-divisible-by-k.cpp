class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) {
            return 1;
        }
        int num = 0;
        for (int i = 1; i <= k; i++) { //no increasing linearly
            num = (num * 10 + 1) % k; //remainders will start repeating
            if (num % k == 0) {
                return i; //if mod == 0 return length i
            }
        }
        return -1;
    }
};