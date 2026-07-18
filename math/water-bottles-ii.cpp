class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles; // first drink all
        while (numExchange <= numBottles) {
            ans++;                     // drink after one exhange
            numBottles -= numExchange; // subtract exchange
            numExchange++;             // increase exchange
            numBottles++;              // the one you drink now
        }
        return ans;
    }
};