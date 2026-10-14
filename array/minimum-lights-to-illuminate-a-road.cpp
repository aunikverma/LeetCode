class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<int> diff(n + 1, 0);

        // mark coverage of existing bulbs
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int v = lights[i];
                int l = max(0, i - v);
                int r = min(n - 1, i + v);

                diff[l] += 1;
                if (r + 1 < n) {
                    diff[r + 1] -= 1;
                }
            }
        }

        int curr = 0, ans = 0, gapLen = 0;
        for (int i = 0; i < n; i++) {
            // prefix sum
            curr += diff[i];
            // not visible
            if (curr == 0) {
                gapLen += 1;
            } else {
                ans += ceil(gapLen / 3.0);
                gapLen = 0;
            }
        }
        // last gap
        ans += ceil(gapLen / 3.0);
        // result

        return ans;
    }
};
//ceil of double divison,since integer division give 1/3 = 0,1/3.0 = 0.33 ceil(0.33) = 1