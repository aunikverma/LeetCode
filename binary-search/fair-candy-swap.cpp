class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int asum = 0, bsum = 0;
        for (int i : a) asum += i;
        for (int i : b) bsum += i;
        int diff = (bsum - asum) / 2;
        unordered_map<int, int> mp;
        for (int i : b) mp[i]++;
        for (int i : a) {
            int need = i + diff;
            if (mp.find(need) != mp.end()) {
                return {i, need};
            }
        }
        return {};
    }
};
// Before swap:
//  Alice sumA --------
//  Bob   sumB ------------------

// diff = (sumB - sumA)/2

// After swap:
//  Alice: sumA - x + y
//  Bob:   sumB - y + x
