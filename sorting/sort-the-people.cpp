class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, int> mp;
        vector<string> ans;
        for (int i = 0; i < heights.size(); i++)
        {
            mp[heights[i]] = i;
        }
        
        for (auto& v : mp) 
        {
            ans.push_back(names[v.second]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};