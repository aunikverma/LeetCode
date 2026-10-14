class Solution {
public:
    string evaluate(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                string a = "";
                while (st.top() != '(') {
                    a += st.top();
                    st.pop();
                }
                st.pop();
                for (char c : a) {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string reverseParentheses(string s) {
        int l = -1, r = -1;
        // first open parenthesis
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                l = i;
                break;
            }
        }
        // first close paranthesis
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                r = i;
                break;
            }
        }
        if (l != -1 && r != -1) {
            string ans = "";
            string inside = evaluate(s.substr(l, r - l + 1));
            if (l > 0) {
                ans += s.substr(0, l);
            }
            ans += inside;
            if (r + 1 < s.length()) {
                ans += s.substr(r + 1);
            }
            return ans;
        }
        return s;
    }
};