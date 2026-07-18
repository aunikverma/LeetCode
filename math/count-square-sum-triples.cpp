class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        unordered_map<double, int> mp;
        for (int i = 1; i <= n; i++) {
            double a = i;
            mp[a]++;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double a = hypot(i, j);
                if (mp.find(a) != mp.end()) {
                    count += 2;
                }
            }
        }
        return count;
    }
};