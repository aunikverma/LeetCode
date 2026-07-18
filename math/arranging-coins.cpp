class Solution {
public:
    int arrangeCoins(int n) {
        int ans = n;
        for (int i = 0; i <= n; i++) {
            ans -= i;
            if (ans < 0) {
                return (i - 1);//n = n - 1,2,3,4 when n < 0 return i-1
            }
        }
        return 1;
    }
};