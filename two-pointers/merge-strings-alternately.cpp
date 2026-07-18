class Solution {
public:
    string mergeAlternately(string w, string w1) {
        string a = "";
        int i = 0,j = 0;
        while (i < w.size() && j < w1.size()) {
            if (i == j) {
                a += w[i];
                i++;
            } else if (j < i) {
                a += w1[j];
                j++;
            }
        }
        while (i < w.size()) {
            a += w[i];
            i++;
        }
        while (j < w1.size()) {
            a += w1[j];
            j++;
        }
        return a;
    }
};