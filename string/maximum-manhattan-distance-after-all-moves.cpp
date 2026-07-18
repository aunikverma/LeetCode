class Solution {
public:
    int maxDistance(string moves) {
        int u = 0, l = 0, r = 0, d = 0, sp = 0;
        for (char c : moves) {
            if (c == 'U') {
                u += 1;
            } else if (c == 'D') {
                d += 1;
            } else if (c == 'L') {
                l += 1;
            } else if (c == 'R') {
                r += 1;
            } else {
                sp += 1;
            }
        }
        // net veritcal + net horizontal
        int base_dis = abs(u - d) + abs(l - r);
        return (base_dis + sp);
    }
};