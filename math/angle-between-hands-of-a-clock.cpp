class Solution {
public:
    double angleClock(int hour, int minutes) {
        // from 0
        double h_angle = (hour == 12 ? 0 : hour * 30) + (minutes * 0.5);
        double m_angle = minutes * 6;

        double ans = abs(m_angle - h_angle);
        ans = min(ans, abs(360 - ans));
        return ans;
    }
};