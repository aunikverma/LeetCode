class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int count = 1;
        ans += count; //for day 1
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] + 1 == prices[i - 1]) { //for continuous decreasing days
                count += 1;
            } else {
                count = 1; //when new period
            }
            ans += count;
        }
        return ans;
    }
};