class Solution {
private:
    int digit(int n) {
        int ans = 1;
        while (n > 0) {
            ans *= n % 10;
            n /= 10;
        }
        return ans;
    }

public:
    int smallestNumber(int n, int t) {
        while(digit(n) % t != 0)
        {
            n++;
        }
        return n;
    }
};