class Solution {
public:
    string reversePrefix(string s, char ch) {
        if(s.find(ch) != -1)
        {
            int a = s.find(ch)+1;
            reverse(s.begin(),s.begin()+a);
        }
        return s;
    }
};