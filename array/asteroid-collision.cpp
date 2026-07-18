class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        stack<int> st;
        for (int i : arr) {
            if (st.empty() || i > 0) {
                st.push(i);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < -i) {
                    st.pop(); // popping till we get negative
                }
                if (st.empty() || st.top() < 0) {
                    st.push(i); // when top is also negative
                }
                if (st.top() == -i) {
                    st.pop(); // when equal
                }
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};