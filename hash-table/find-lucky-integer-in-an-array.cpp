class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        for (int i : arr) {
            mp[i]++;
        }
        int ans = -1;
        for (auto& v : mp) {
            if (v.first == v.second) {
                ans = max(ans, v.first);
            }
        }
        return ans;
    }
};