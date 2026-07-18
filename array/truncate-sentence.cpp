class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0;
        int a = 0;
        string ans = "";
        while(i < s.length())
        {
            if(s[i] == ' ')
            {
                a++;
                if(a == k)
                {
                    return ans;
                }
            }
            ans += s[i];
            i++;
        }
        return ans;
    }
};