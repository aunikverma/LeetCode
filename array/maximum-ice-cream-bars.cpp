class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;
        sort(costs.begin(), costs.end());
        int i = 0;
        while (i < costs.size() && coins > 0) {
            if (coins - costs[i] >= 0) {
                coins -= costs[i];
                count += 1;
                i += 1;
            } else {
                break;
            }
        }
        return count;
    }
};