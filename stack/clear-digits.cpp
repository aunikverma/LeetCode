class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans;
        for (char c : s) {
            if (c >= '0' && c <= '9' && !st.empty()) {
                st.pop();//if digit pop the last character
            } else {
                st.push(c);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();//adding string into ans
        }
        reverse(ans.begin(), ans.end());//reversing it 
        return ans;
    }
};