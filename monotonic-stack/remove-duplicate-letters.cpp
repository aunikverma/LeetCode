class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a'] += 1;
        }
        vector<bool> used(26, false);
        stack<char> st;

        for (char c : s) {
            // sub from freq
            freq[c - 'a'] -= 1;
            // if used continue
            if (used[c - 'a']) {
                continue;
            }
            // if less than st.top() and present further in string
            while (!st.empty() && c < st.top() && freq[st.top() - 'a'] > 0) {
                used[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            used[c - 'a'] = true;
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};