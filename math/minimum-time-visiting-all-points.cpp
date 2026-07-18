class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int steps = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[i + 1][0], y2 = points[i + 1][1];
            int dx = abs(x1 - x2), dy = abs(y1 - y2); //draw diagram easy to understand
            steps += min(dy, dx) + abs(dy - dx); //go diagonal then horizontal or vertical
        }
        return steps;
    }
};