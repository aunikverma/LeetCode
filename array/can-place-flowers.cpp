class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        if (n == 0)
            return true;
        for (int i = 0; i < bed.size(); i++) {
            if (bed[i] == 0 && (i == 0 || bed[i - 1] == 0) && (i == bed.size() - 1 || bed[i + 1] == 0)) {
                bed[i] = 1;
                n -= 1;
            }
            if (n == 0) {
                return true;
            }
        }
        return false;
    }
};