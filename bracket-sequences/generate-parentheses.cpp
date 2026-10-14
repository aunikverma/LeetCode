class Solution {
public:
    void solve(int& n, string& s, int balance, vector<string>& ans) {
        if (balance < 0) {
            return;
        }
        if (s.length() > n * 2) {
            return;
        }
        if (s.length() == n * 2 && balance == 0) {
            ans.push_back(s);
            return;
        }
        // try open
        s += '(';
        balance += 1;
        solve(n, s, balance, ans);
        balance -= 1;
        s.pop_back();
        // try close
        s += ')';
        balance -= 1;
        solve(n, s, balance, ans);
        balance += 1;
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        int balance = 0;
        solve(n, s, balance, ans);
        return ans;
    }
};