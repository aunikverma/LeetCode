class Solution {
public:
    int heightChecker(vector<int>& he) {
        vector<int>h(he.begin(),he.end());
        sort(h.begin(),h.end());
        int ans = 0;
        for(int i = 0;i < he.size();i++)
        {
            if(he[i] != h[i])
            {
                ans++;
            }
        }
        return ans;
    }
};