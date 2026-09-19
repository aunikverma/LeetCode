class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        int x_nearest = min({xCenter, x1, x2});
        int y_nearest = min({yCenter, y1, y2});

        int dist = sqrt((x_nearest - xCenter) * (x_nearest - xCenter) +
                        (y_nearest - yCenter) * (y_nearest - yCenter));
        return (dist <= radius);
    }
};