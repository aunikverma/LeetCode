class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,vector<vector<int>>& topRight) {
        int n = bottomLeft.size(); // topright
        int maxSide = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // width
                int topRightx = min(topRight[i][0], topRight[j][0]);
                int bottomLeftx = max(bottomLeft[i][0], bottomLeft[j][0]);
                int width = topRightx - bottomLeftx;

                // height
                int topRighty = min(topRight[i][1], topRight[j][1]);
                int bottomLefty = max(bottomLeft[i][1], bottomLeft[j][1]);
                int height = topRighty - bottomLefty;
                //side
                int side = min(width, height);
                // maxSide
                maxSide = max(maxSide, side);
            }
        }
        return (1LL * maxSide * maxSide);
    }
};