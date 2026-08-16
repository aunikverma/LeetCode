class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int zeros = 0, ones = 0, twos = 0;
        for (int i : stones) {
            zeros += (i % 3 == 0 ? 1 : 0);
            ones += (i % 3 == 1 ? 1 : 0);
            twos += (i % 3 == 2 ? 1 : 0);
        }
        if (zeros % 2 == 0) {
            // Normal case
            if (ones == 0 || twos == 0) {
                return max(ones, twos) >= 3;
            }
            return true;
        } else {
            // Flipped case
            if (ones == 0 || twos == 0) {
                return false;
            }
            return abs(ones - twos) >= 3;
        }
    }
};