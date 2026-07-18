class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        for (string s : op) {
            if (isdigit(s[0]) || s[0] == '-' && s.size() > 1) {
                st.push(stoi(s));
            } else if (s == "C") {
                st.pop();
            } else if (s == "D") {
                st.push(2 * st.top());
            } else if (s == "+") {
                if (st.size() >= 2) {
                    int a = st.top();
                    st.pop();
                    int c = st.top();
                    st.push(a);
                    st.push(a + c);
                }
            }
        }
        int s = 0;
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        return s;
    }
};