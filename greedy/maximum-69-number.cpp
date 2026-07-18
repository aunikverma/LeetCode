class Solution {
public:
    int maximum69Number(int num) {
        string a = "";
        string s = to_string(num);
        int k = 0;
        for (char c : s) {
            if (c == '9') {
                a += c;
            } else {
                if (c == '6' && k == 0) { //finding first six and change to 9 then rest same
                    a += '9';
                    k++;
                } else {
                    a += c;
                }
            }
        }
        return stoi(a);
    }
};