class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            if (pref.length() <= words[i].length()) {
                string a = words[i].substr(0, pref.length());//getting prefix
                if (a == pref) {//if equal then increment ans
                    ans++;
                }
            }
        }
        return ans;//return ans
    }
};