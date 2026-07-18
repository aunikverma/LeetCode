class Solution {
public:
    vector<int> stableMountains(vector<int>& h, int k) {
        vector<int> ans;
        for (int i = h.size() - 1; i >= 1; i--) {
            if (h[i - 1] > k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};