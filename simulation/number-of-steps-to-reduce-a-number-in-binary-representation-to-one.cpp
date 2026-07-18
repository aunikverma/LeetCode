class Solution {
public:
    int numSteps(string s) {
        int carry = 0, ans = 0;
        for (int i = s.length() - 1; i >= 1; i--) {
            if ((s[i] - '0') + carry % 2 == 1) {
                ans += 2;
                carry = 1;
            } else {
                ans++;
            }
        }
        return (ans + carry);
    }
};
// when odd take 2 opns
// when even take 1 to remove last bit
// given s[0] = '1'