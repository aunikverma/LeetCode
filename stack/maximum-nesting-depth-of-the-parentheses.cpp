class Solution {
public:
    int maxDepth(string s) {
        int balance = 0, ans = -1;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if(c == ')'){
                balance--;
            }
            ans = max(ans, balance);
        }
        return ans;
    }
};