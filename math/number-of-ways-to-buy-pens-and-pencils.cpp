class Solution {
public:
    long long waysToBuyPensPencils(int t, int c1, int c2) {
        long long a;
        if (c1 > t && c2 > t) {
            return 1;
        }
        for (int i = 0; i <= t / c1; i++) {
            a += (t - (c1 * i)) / c2 + 1;
            // for every buy how much money left and check how much other we can
            // buy
        }
        return a;
    }
};