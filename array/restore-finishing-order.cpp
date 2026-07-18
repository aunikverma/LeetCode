class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans(friends.size(), 0);
        unordered_map<int, int> mp;
        for (int i : friends) {
            mp[i]++;
        }
        int i = 0;
        for (int j : order) {
            if (mp.find(j) != mp.end()) {
                ans[i++] = j;
            }
        }
        return ans;
    }
};