class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int total = 0, res = 0, sum = 0;
        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            sum += satisfaction[i];
            if (sum > 0) {
                total += sum;
                res = max(res, total);
            } else {
                break;
            }
        }
        return res;
    }
};