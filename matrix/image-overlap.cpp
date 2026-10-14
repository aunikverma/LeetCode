class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for (int i = -n + 1; i < n; i++) {
            for (int j = -n + 1; j < n; j++) {
                // now to check which are overlapping
                int count = 0;
                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < n; c++) {
                        int n_r = r + i;
                        int n_c = c + j;
                        if (n_r >= 0 && n_r < n && n_c >= 0 && n_c < n) {
                            if (img1[r][c] == 1 && img2[n_r][n_c] == 1) {
                                count += 1;
                            }
                        }
                    }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
// row offset if we overlap whole image and move the img1
// row offset will be (-n + 1 <= x <= n - 1)
// similarly col offset will be(-n + 1 <= x <= n - 1)
