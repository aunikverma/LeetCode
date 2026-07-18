class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        vector<pair<int, int>> v; // score and index
        for (int i = 0; i < score.size(); i++) {
            v.push_back({score[i], i});
        }
        sort(v.rbegin(), v.rend());
        int c = 1;
        for (auto i : v) {
            if (c == 1) {
                ans[i.second] = "Gold Medal";
            } else if (c == 2) {
                ans[i.second] = "Silver Medal";
            } else if (c == 3) {
                ans[i.second] = "Bronze Medal";
            } else {
                ans[i.second] = to_string(c);
            }
            c++;
        }
        return ans;
    }
};