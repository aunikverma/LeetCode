class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> yTox; // constant y
        unordered_map<int, pair<int, int>> xToy; // constant x

        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            if (!yTox.count(y)) {
                yTox[y] = {INT_MAX, INT_MIN};
            }
            if (!xToy.count(x)) {
                xToy[x] = {INT_MAX, INT_MIN};
            }
            // for y axis
            yTox[y].first = min(yTox[y].first, x);   // updating min x
            yTox[y].second = max(yTox[y].second, x); // updating max x
            // for x axis
            xToy[x].first = min(xToy[x].first, y);   // updating min y
            xToy[x].second = max(xToy[x].second, y); // updating max y
        }
        int count = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            auto& xr = yTox[y];
            auto& yr = xToy[x];

            if (xr.first < x && x < xr.second && yr.first < y && y < yr.second) {
                count++;
            }
        }
        return count;
    }
};