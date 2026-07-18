class Solution {
public:
    string defangIPaddr(string s) {
        string ans = "";
        for(char c : s)
        {
            if(c != '.') ans += c;
            else ans += "[.]";
        }
        return ans;
    }
};