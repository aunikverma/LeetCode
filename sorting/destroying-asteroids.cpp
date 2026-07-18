class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long planet = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int i = 0; i < n; i++) {
            if (planet < asteroids[i]) {
                return false;
            }
            planet += asteroids[i];
        }
        return true;
    }
};