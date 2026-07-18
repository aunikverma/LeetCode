class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = s.length() - 1;i >= 1;i--)
        {
            if(s[i] == '1' && s[i - 1] == '0')//from behind if 1 and its left is zero then false
            {
                return false;//since s[0] is always 1
            }
        }
        return true;
    }
};