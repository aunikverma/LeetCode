class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;//base case
        if (n >= 1 && n <= 5) return true; // base case
        if(n % 2 == 0) return isUgly(n/2);
        if(n % 3 == 0) return isUgly(n/3);
        if(n % 5 == 0) return isUgly(n/5);
        return false;
    }
};