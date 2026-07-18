class Solution {
public:
    bool isValid(string w) {
        int v = 0,c = 0;//for vowel and consonants
        if(w.length() < 3) return false;
        set<char>s = {'a','e','i','o','u'};
        for(int i = 0;i < w.size();i++)
        {
            if(!isalnum(w[i])) return false;
            else if(w[i] >= '0' && w[i] <= '9') continue;
            else if(s.find(tolower(w[i])) != s.end())
            {
                v++;
            }
            else
            {
                c++;
            }
        }
        if(c > 0 && v > 0) return true;
        return false;
    }
};