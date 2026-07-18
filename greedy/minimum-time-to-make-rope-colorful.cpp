class Solution {
public:
    int minCost(string s, vector<int>& time) {
        int ans = 0;
        // since if n consecutive ballons are of same color then we have to
        // remove n - 1 ballons
        for (int i = 1;i < s.length();i++) {
            if(s[i] == s[i -  1])
            {
                ans += min(time[i],time[i - 1]);
                time[i] = max(time[i],time[i - 1]);
            }
        }
        return ans;
    }
};