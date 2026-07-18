class Solution {
public:
    int reverse(long x) {
        long  ans = 0;
        while(x != 0)
        {
            int digit = x%10;
            ans = ans*10 + digit;
            x = x/10;
        }
        if(ans <= INT_MAX &&  ans >= INT_MIN)
            {
                return ans;
            }
        return 0;
    }
};