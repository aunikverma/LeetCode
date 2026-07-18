class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles; //left
        while (empty >= numExchange) {
            ans += (empty / numExchange);
            empty = (empty / numExchange) + (empty % numExchange); //left bottle update
        }
        return ans;
    }
};