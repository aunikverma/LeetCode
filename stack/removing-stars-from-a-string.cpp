class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '*') {
                st.pop();
            } else {
                st.push(c);
            }
        }
        string a = "";
        while (!st.empty()) {
            a += st.top();
            st.pop();
        }
        reverse(a.begin(), a.end());
        return a;
    }
};