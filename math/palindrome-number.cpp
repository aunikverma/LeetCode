class Solution {
public:
    bool isPalindrome(int x) {
        long n = x;
        long ans;
        if (x < 0) {
            return false;
        }
        while (n) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return (ans == x);
    }
};