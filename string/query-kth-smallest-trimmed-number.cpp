class Solution {
public:
    bool static Comp(const pair<string, int>& a, const pair<string, int>& b) {
        if (a.first == b.first) {
            return (a.second < b.second);
        }
        return (a.first < b.first);
    }

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int len = nums[0].length();
        vector<int> ans;
        for (auto i : queries) {
            int k = i[0], trim = i[1];
            vector<pair<string, int>> trimmed;
            for (int j = 0; j < nums.size(); j++) {
                string s = nums[j].substr(len - trim);
                trimmed.push_back({s, j});
            }
            sort(trimmed.begin(), trimmed.end(), Comp);
            ans.push_back(trimmed[k - 1].second);
        }
        return ans;
    }
};