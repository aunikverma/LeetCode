class Solution {
public:
    string greatestLetter(string s) {
        string a = "";
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                if (s.find(toupper(c)) != -1) {
                    a += toupper(c);
                }
            } else if (c >= 'A' && c <= 'Z') {
                if (s.find(tolower(c)) != -1) {
                    a += c;
                }
            }
        }
        if (a == "")
            return "";
        sort(a.rbegin(), a.rend());
        string ans = "";
        ans += a[0];
        return ans;
    }
};