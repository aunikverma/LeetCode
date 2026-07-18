class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        for (char c : s) {
            mp[c]++;
        }
        for (char c : target) {
            mp1[c]++;
        }
        int ans = INT_MAX;
        for (auto& v : mp1) {
            int c = mp[v.first] / v.second; //minimum by dividing
            ans = min(ans, c);
        }
        return ans;
    }
};