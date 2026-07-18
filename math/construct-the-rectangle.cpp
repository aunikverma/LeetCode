class Solution {
public:
    vector<int> constructRectangle(int area) {
        // since the w is always less then or equal to sqrt(area)
        // and we want l >= w
        int w = -1;
        for (int i = 1; i <= sqrt(area); i++) { //maximum width which is dividing area
            if (area % i == 0) {
                w = max(i, w);
            }
        }
        int l = area / w; //length = area / w
        return {l, w};
    }
};