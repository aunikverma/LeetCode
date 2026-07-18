class Solution {
private:
    bool isValid(string s) {
        if (s[0] == ')')
            return false; // if first is closing then false
        stack<char> st;
        for (char c : s) {
            if (st.empty() || (c == '(')) {
                st.push(c); // if opening then push
            } else {
                if (c == ')' && st.top() == '(')
                    st.pop(); // if closing and st.top == opening then pop
                else
                    return false; // else false if any other closing bracket
            }
        }
        if (st.size() == 0) // in last if size == 0 then true
            return true;
        return false;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        for (int i = 1; i <= n; i++) {
            s += '(';
        }
        for (int i = 1; i <= n; i++) {
            s += ')';
        }
        ans.push_back(s);
        while (next_permutation(s.begin(), s.end())) {
            if (isValid(s)) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};