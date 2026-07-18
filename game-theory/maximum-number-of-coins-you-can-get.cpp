class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(), p.end());
        int m = 0;
        int i = p.size() - 2;
        int c = 0;
        while (c != p.size() / 3) {
            m += p[i];
            i -= 2;
            c++; // maximum piles you can take is p.size() / 3
        }
        return m;
    }
};