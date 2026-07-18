class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = "";
        sort(v.begin(),v.end());
        string f = v[0];//first word
        string l = v[v.size() - 1];//last word
        for(int i = 0;i < min(f.size(),l.size()) ;i++)
        {
            if(f[i] != l[i])
            {
                break;
            }
            ans += f[i];
        } 
        return ans;
    }
};