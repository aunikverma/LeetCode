class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char, long long> mp;
        long long total_cost = 0;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = 0;
            }
            mp[s[i]] += cost[i];
            total_cost += cost[i];
        }
        long long ans = LLONG_MAX;
        for (auto& v : mp) {
            ans = min(ans, total_cost - v.second);
        }
        return ans;
    }
};