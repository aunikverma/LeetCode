class Solution {
public:
    int findClosest(int x, int y, int z) {
        int one = abs(z - x);
        int two = abs(z - y);
        if (one == two) {
            return 0;
        } else {
            return (one > two) ? 2 : 1;
        }
    }
};