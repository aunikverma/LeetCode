class Solution {
public:
    int countSegments(string s) {
        if(s.length() == 0) return 0;
        int a = 0;
        for(int i = 0;i < s.length();i++)
        {
            if((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
            {
                a++;
            }
        }
        return a;
    }
};