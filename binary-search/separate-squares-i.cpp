class Solution {
public:
    bool check(vector<vector<int>>& squares, double mid_y, double total) {
        double bot_area = 0;
        for (auto& sq : squares) {
            double y = sq[1], l = sq[2];
            double boty = y, topy = y + l;
            if (mid_y >= topy) {
                // full sq below
                bot_area += l * l;
            } else if (mid_y > boty) {
                // partial area below
                bot_area += l * (mid_y - boty);
            }
        }
        return bot_area >= total / 2.0; // is bottom area more than above
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX, high = INT_MIN, total = 0.0000;
        for (auto& sq : squares) {
            double x = sq[0], y = sq[1], l = sq[2];
            total += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }
        double result_y = 0.0000;
        while (high - low > 1e-5) {
            double mid_y = low + (high - low) / 2;
            result_y = mid_y;
            if (check(squares, mid_y, total)) {
                high = mid_y;
            } else {
                low = mid_y;
            }
        }
        return result_y;
    }
};