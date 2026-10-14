class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0, start = 0;
        string ans = "";
        for (int i = 0;i < s.length();i++) {
            if (s[i] == '(') { //balance get 0
                balance++;
            } else {
                balance--;
            }
            if (balance == 0) {
                ans += s.substr(start + 1, i - start - 1); //start index ,length
                start = i + 1;
            }
        }
        return ans;
    }
};