class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        string s1 = ""; // counting substring
        int i = 0;
        while (i < s.length()) {
            s1 = s.substr(i, k);
            i += k;
            int m = 0;
            for (char c1 : s1) {
                m += c1 - 'a';//counting char no
            }
            ans += char((m % 26) + 'a');//adding it no new string
        }
        return ans;
    }
};