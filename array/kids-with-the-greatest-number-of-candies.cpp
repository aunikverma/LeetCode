class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ex) {
        vector<bool> ans;
        int m = INT_MIN;
        for (int i : c) {
            m = max(m, i);
        }
        for (int i : c) {
            if (i + ex >= m) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};