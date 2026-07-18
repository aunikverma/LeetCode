class Solution {
public:
    int maxRepeating(string s, string word) {
        int ans = 0;
        string t = word;
        while(s.find(t) != string :: npos)//no position use
        {
            ans ++;
            t += word;
        }
        return ans;
    }
};