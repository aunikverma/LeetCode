class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
                                          vector<vector<int>>& items2) {
        unordered_map<int, int> mp;
        for (auto i : items1) {
            if (mp.count(i[0])) {
                mp[i[0]] = mp[i[0]] + i[1]; // if i[0] in map so update
            } else {
                mp[i[0]] = i[1]; // else insert
            }
        }
        for (auto i : items2) { // doing same for items2
            if (mp.count(i[0])) {
                mp[i[0]] = mp[i[0]] + i[1];
            } else {
                mp[i[0]] = i[1];
            }
        }
        vector<vector<int>> ans;
        for (auto& v : mp) { // adding in ans then sort
            ans.push_back({v.first, v.second});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};