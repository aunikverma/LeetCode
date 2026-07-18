class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end());
        int i = n - 1;
        int min_cost = 0;
        while (i >= 0) {
            int c1 = cost[i];
            int c2 = (i - 1 >= 0 ? cost[i - 1] : 0);
            min_cost += c1 + c2;
            i -= 3;
        }
        return min_cost;
    }
};