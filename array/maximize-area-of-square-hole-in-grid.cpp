class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxconshbars = 1, maxconsvbars = 1;
        int currconshbars = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] == 1) {
                currconshbars++;
            } else {
                currconshbars = 1;
            }
            maxconshbars = max(maxconshbars, currconshbars);
        }
        int currconsvbars = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] == 1) {
                currconsvbars++;
            } else {
                currconsvbars = 1;
            }
            maxconsvbars = max(maxconsvbars, currconsvbars);
        }
        int side = min(maxconshbars, maxconsvbars) + 1;
        return (side * side);
    }
};