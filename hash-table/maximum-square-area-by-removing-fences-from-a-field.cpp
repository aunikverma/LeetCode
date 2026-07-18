class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> widths;
        int maxSide = 0, M = 1e9 + 7;

        // finding all widhts that are possible
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int width = vFences[j] - vFences[i];
                widths.insert(width);
            }
        }
        // finding if any height in width
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                int height = hFences[j] - hFences[i];
                if (widths.find(height) != widths.end()) {
                    // updating maxSide
                    maxSide = max(maxSide, height);
                }
            }
        }
        return maxSide == 0 ? -1 : (1LL * maxSide * maxSide) % M;
    }
};