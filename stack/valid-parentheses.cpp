class Solution {
public:
    bool isValid(string s) {
        if (s[0] == ')' || s[0] == '}' || s[0] == '}')
            return false; // if first is closing then false
        stack<char> st;
        for (char c : s) {
            if (st.empty() || (c == '(' || c == '[' || c == '{')) {
                st.push(c); // if opening then push
            } else {
                if (c == ')' && st.top() == '(')
                    st.pop(); // if closing and st.top == opening then pop
                else if (c == ']' && st.top() == '[')
                    st.pop();
                else if (c == '}' && st.top() == '{')
                    st.pop();
                else
                    return false; // else false if any other closing bracket
            }
        }
        if (st.size() == 0) // in last if size == 0 then true
            return true;
        return false;
    }
};