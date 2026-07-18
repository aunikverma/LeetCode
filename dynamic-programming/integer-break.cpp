class Solution {
public:
    int integerBreak(int n) {
        //since the product canbe maximum if break into 3
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        
        int ans = 1;
        //greater than last base case extract most 3s
        while(n > 4)
        {
            ans *= 3;
            n -= 3;
        }
        //last no
        ans *= n;
        return ans;
    }
};