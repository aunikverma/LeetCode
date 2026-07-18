class Solution {
public:
    string rev(string s) {
        reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.length() && s[i] == '0') {
            i++;
        }
        s = s.substr(i);
        return s;
    }

    bool isSameAfterReversals(int num) {
        if (num == 0) {
            return true;
        }
        string a = to_string(num);
        string b = rev(rev(a));
        return (a == b);
    }
};