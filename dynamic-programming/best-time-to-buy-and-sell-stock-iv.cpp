class Solution {
public:
    int solveTabSpace(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int l = k - 1; l >= 0; l--) {
                    int not_take = next[buy][l];
                    int take = 0;
                    if (buy) {
                        take = next[1 - buy][l] - prices[i];
                    } else {
                        take = next[1 - buy][l + 1] + prices[i];
                    }
                    curr[buy][l] = max(take, not_take);
                }
                next = curr;
            }
        }
        return curr[1][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        return solveTabSpace(k, prices);
    }
};