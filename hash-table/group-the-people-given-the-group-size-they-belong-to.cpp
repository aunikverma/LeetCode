class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < g.size(); i++) // group
        {
            mp[g[i]].push_back(i);
            if (mp[g[i]].size() == g[i]) {
                ans.push_back(mp[g[i]]);
                mp[g[i]].clear(); // Reset the group for the next potential group
            }
        }
        return ans;
    }
};