class Solution {
public:
    int divide(int q, int d) {
        if (q == INT_MIN && d == -1)
            return INT_MAX;
        if (q == INT_MIN && d == 1)
            return INT_MIN;
        bool n = (q < 0) ^ (d < 0);//if both are of opposite signs then true
        long long q1 = abs((long long)q);//long long due to overflow
        long long d1 = abs((long long)d);

        int ans = 0;//quotient in ans

        while(q1 >= d1)//while q1 >= d1 becouse we are subtracting in each iteration highest multiple
        {
            long long t = d1;
            long long m = 1;//multiple 1
            while(q1 >= (t << 1))
            {
                t <<= 1;//doubles every time
                m <<= 1;//dowbles every time
            }
            q1 -= t;//sub highest multiple
            ans += m;//adding it to the ans
        }
        return (n ? -ans : ans);//if n true then -ans else ans
    }
};