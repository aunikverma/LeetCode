class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        pair<int, int> p(0, 0);
        for (char c : s) {
            if (c == '0') {
                p.first++;
            } else {
                p.second++;
            }
        }
        string a = "";
        if (p.second == 1) {
            for (int i = 0; i < p.first; i++) {
                a += '0';
            }
            a += '1';
            return a;
        } else {
            for (int i = 0; i < p.second - 1; i++) {
                a += '1';
            }
            for (int i = 0; i < p.first; i++) {
                a += '0';
            }
            a += '1';
        }
        return a;
    }
};