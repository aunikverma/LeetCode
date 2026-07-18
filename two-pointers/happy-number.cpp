class Solution {
private:
    int sqdigitsum(int n)
    {
        int s = 0;
        while(n > 0)
        {
            int r = n%10;
            s += r*r;
            n /= 10;
        }
        return s;
    }
public:
    bool isHappy(int n) {
        int s = sqdigitsum(n);
        int f = sqdigitsum(sqdigitsum(n));
        while(s != f && f != 1)
        {
            s = sqdigitsum(s);
            f = sqdigitsum(sqdigitsum(f));
        }
        return (f == 1);
    }
};