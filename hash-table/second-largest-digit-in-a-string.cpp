class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                st.insert(c - '0');
            }
        }
        if (st.size() < 2) {
            return -1;
        }
        auto it = st.rbegin();
        it++;
        return *it;
    }
};