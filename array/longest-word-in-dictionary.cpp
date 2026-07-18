class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());//sort because we want smaller one
        unordered_map<string, int> mp;
        for (auto i : words) {
            mp[i]++; //storing words in map
        }
        string ans = "";
        for (auto i : words) {
            string s = "";
            int v = 0;
            for (char c : i) {
                s += c;
                if (mp.find(s) != mp.end()) v++; //check every prefix is in words
            }
            if (v == i.length() && i.length() > ans.length()) { //if yes and bigger then ans 
                ans = i; //update ans
            }
        }
        return ans;
    }
};