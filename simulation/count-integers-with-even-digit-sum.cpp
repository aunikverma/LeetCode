class Solution {
private : 
    int digitsum(int n)
    {
        int s = 0;
        while(n > 0)
        {
            s += n%10;
            n /= 10;
        }
        return s;
    }
public:
    int countEven(int num) {
        int c = 0;
        for(int i = 1;i <= num;i++)
        {
            if(digitsum(i) % 2 == 0)
            {
                c++;
            }
        }
        return c;
    }
};