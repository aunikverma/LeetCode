class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Initial base for the valid substring
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push the index of '('
            } else {
                st.pop(); // Pop for a matching ')'
                if (st.empty()) {
                    st.push(i); // Update the base index
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};
