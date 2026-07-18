class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey,
                     string ruleValue) {
        int row = items.size();
        int k = 0;
        int ans = 0;
        if (ruleKey == "type") {
            k = 0;
        } else if (ruleKey == "color") {
            k = 1;
        } else {
            k = 2;
        }
        for (int i = 0; i < row; i++) {
            if (ruleValue == items[i][k]) {
                ans++;
            }
        }
        return ans;
    }
};