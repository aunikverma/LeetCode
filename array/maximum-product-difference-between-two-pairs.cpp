class Solution {
public:
    int maxProductDifference(vector<int>& n) {
        sort(n.begin(), n.end());
        return ((n[n.size() - 1] * n[n.size() - 2]) - (n[0] * n[1]));
    }
};