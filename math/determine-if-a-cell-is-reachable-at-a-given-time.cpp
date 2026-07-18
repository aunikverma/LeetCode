class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(fx - sx);
        int dy = abs(fy - sy);
        // since we can move into diagonals
        int minTime = max(dx, dy);
        if (t < minTime) {
            return false;
        }
        // moving back and forth
        if (t == 1 && sx == fx && sy == fy) {
            return false;
        }
        return true;
    }
};