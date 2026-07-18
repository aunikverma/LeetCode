class Solution {
public:
    int myAtoi(string s) {
        string n = "";
        bool pos = true;
        int i = 0;

        // eliminate whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        // whole string consumed
        if (i == s.length()) {
            return 0;
        }
        // sign
        if (s[i] == '-' || s[i] == '+') {
            pos = (s[i] == '+');
            i++;
        }
        // read digits
        for (int j = i; j < s.length(); j++) {
            if (isdigit(s[j])) {
                if (s[j] != '0' || !n.empty()) {
                    n += s[j];
                }
            } else {
                break;
            }
        }
        // check n
        if (n.empty()) {
            return 0;
        }
        // overflow check
        if (n.length() > 10) {
            return (pos ? INT_MAX : INT_MIN);
        }
        if (n.length() == 10) {
            if (pos && n >= "2147483647") {
                return INT_MAX;
            }
            if (!pos && n >= "2147483648") {
                return INT_MIN;
            }
        }
        // answer
        int ans = stoi(n);
        return (pos ? ans : -ans);
    }
};