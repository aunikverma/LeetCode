class Solution {
public:
    bool judgeCircle(string moves) {
        int r = 0, l = 0, u = 0, d = 0; // right,left,up,down
        for (char c : moves) {
            if (c == 'U') {
                u++;
            } else if (c == 'D') {
                d++;
            } else if (c == 'R') {
                r++;
            } else {
                l++;
            }
        }
        if (r == l && u == d) {
            return true;
        }
        return false;
    }
};