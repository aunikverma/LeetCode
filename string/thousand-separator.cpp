class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) {
            return "0";
        }
        string s = "";
        int count = 0;
        while (n > 0) {
            if (count % 3 == 0) {
                s += '.';
                count = 0;
            }
            s += to_string(n % 10);
            n /= 10;
            count++;
        }
        reverse(s.begin(), s.end());
        return s.substr(0, s.length() - 1);
    }
};