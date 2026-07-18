class Solution {
public:
    string baseNeg2(int n) {
        string ans = "";
        while (n) {
            ans = to_string(n & 1) + ans;
            n = -(n >> 1);//for base -2
        }
        return (ans == "" ? "0" : ans);//if n == 0 return "0"
    }
};