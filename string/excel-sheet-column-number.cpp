class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int k = 0;
        for(int i  = s.length() - 1;i >= 0 ;i--)
        {
            ans += (++s[i] - 'A')*pow(26,k++);
        }
        return ans;
    }
};