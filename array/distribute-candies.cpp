class Solution {
public:
    int distributeCandies(vector<int>& c) {
        int n = c.size() / 2;//no of candies alice can eat
        set<int>s(c.begin(),c.end());
        int n1 = s.size();
        int ans = min(n,n1);
        return ans;
    }
};