class Solution {
public:
    int subtractProductAndSum(int n) {
        int pr = 1 ,sum = 0 ;
        while(n > 0)
        {
            int rem = n%10;
            pr *= rem;
            sum += rem;
            n = n/10;
        }
        return (pr - sum);
    }
};