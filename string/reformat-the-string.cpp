class Solution {
public:
    string reformat(string s) {
        string digits = "", chars = "";
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                digits += c;
            } else {
                chars += c;
            }
        }
        int a = digits.length(), b = chars.length();
        if (abs(a - b) > 1) {
            return "";
        }
        string ans = "";
        int i = 0, j = 0;
        if (a > b) {
            while (i < a || j < b) {
                if (i < a) {
                    ans += digits[i];
                }
                if (j < b) {
                    ans += chars[j];
                }
                i++;
                j++;
            }
        } else {
            while (i < a || j < b) {
                if (j < b) {
                    ans += chars[j];
                }
                if (i < a) {
                    ans += digits[i];
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};