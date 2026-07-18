class Solution {
public:
    int maxArea(vector<int>& ht) {
        int i = 0;
        int j = ht.size() - 1;
        int width, h, currwater = 0;
        while (i < j) {
            width = j - i;
            h = min(ht[i], ht[j]);
            currwater = max(h * width, currwater);
            if (ht[i] < ht[j]) {
                i++;
            } else {
                j--;
            }
        }
        return currwater;
    }
};