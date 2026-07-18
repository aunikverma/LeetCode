class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> mp;
        vector<string>ans;
        string a = "qwertyuiop"; // row 1
        string b = "asdfghjkl";  // row 2
        string c = "zxcvbnm";    // row 3
        for (char i : a) {
            mp[i] = 1;
        }
        for (char i : b) {
            mp[i] = 2;
        }
        for (char i : c) {
            mp[i] = 3;
        }
        for(auto &v : words)
        {
            set<int>s;
            for(char c : v)
            {   
                s.insert(mp[tolower(c)]);
            }
            if(s.size() == 1)
            {
                ans.push_back(v);
            }
        }
        return ans;
    }
};