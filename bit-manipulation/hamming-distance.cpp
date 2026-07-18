class Solution {
public:
    int hammingDistance(int s, int g) {
        int d = s ^ g;
        int c = 0;
        while (d) {
            if (d & 1) {
                c++;
            }
            d >>= 1;
        }
        return c;
    }
};