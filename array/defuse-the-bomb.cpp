class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n,0);
        if(k == 0) return ans;
        if(k > 0)
        {
            //sum next k in circular
            for(int i = 0;i < n;i++)
            {
                for(int j = 1;j <= k;j++)
                {
                    ans[i] += code[(i + j) % n];
                }
            }
        }
        else if(k < 0)
        {
            //sum of previous -k elements in circular manner
            for(int i = 0;i < n;i++)
            {
                for(int j = 1;j <= -k;j++)
                {
                    ans[i] += code[(i - j + n) % n];
                }
            }
        }
        return ans;
    }
};