class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = -1;
        // fix n - 1
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = max(ans, abs(n - 1 - i));
                break;
            }
        }
        // fix 0
        for (int j = n - 1; j >= 1; j--) {
            if (colors[j] != colors[0]) {
                ans = max(ans, j);
                break;
            }
        }
        return ans;
    }
};