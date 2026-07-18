class Solution {
public:
    bool isPalindrome(string& s) 
    {
        int i = 0;
        int j = s.size()- 1;
        while (i < j)
        if (! isalnum(s[i]))
            i += 1;
        else if (!isalnum(s[j]))
            j -= 1;
        else if (tolower(s[i]) != tolower(s[j]))
            return false;
        else 
        {
            i += 1;
            j -= 1;
        }
        return true;
    }
};