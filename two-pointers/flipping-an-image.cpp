class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            for (int k = 0; k < n; k++) {
                swap(image[k][i], image[k][j]);
            }
            i++;
            j--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == 0) {
                    image[i][j] = 1;
                } else {
                    image[i][j] = 0;
                }
            }
        }
        return image;
    }
};