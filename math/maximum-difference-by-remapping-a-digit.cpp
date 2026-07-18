class Solution {
public:
    int minMaxDifference(int num) {
        string a = to_string(num);
        string s = "", s1 = "";
        char c, c1;
        for (int i = 0; i < a.length(); i++) // finding first non-nine digit
        {
            if (a[i] != '9') {
                c = a[i];
                break;
            }
        }
        for (int i = 0; i < a.length(); i++) // finding first non-zero digit
        {
            if (a[i] != '0') {
                c1 = a[i];
                break;
            }
        }
        // replacing to make largest digit
        for (char x : a) {
            if (x == c) {
                s += '9';
            } else {
                s += x;
            }
        }
        // to make smallest
        for (char x : a) {
            if (x == c1) {
                s1 += '0';
            } else {
                s1 += x;
            }
        }

        return (stoi(s) - stoi(s1));
    }
};