class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char>v(indices.size());
        for(int i = 0;i < indices.size();i++)
        {
            v[indices[i]] = s[i];
        }
        string ans = "";
        for(auto &c : v)
        {
            ans += c;
        }
        return ans;
    }
};