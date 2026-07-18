class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ans = INT_MAX;
        // try for every pos
        for (int i = 0; i < position.size(); i++) {
            int count = 0;
            for (int j = 0; j < position.size(); j++) {
                if ((position[j] - position[i]) & 1) {
                    count++;
                }
            }
            // store min
            ans = min(ans, count);
        }
        return ans;
    }
};