class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> used(26, false);
        string ans = "";
        for (char c : s) {
            count[c - 'a']++;
        }
        stack<char> st;
        for (char c : s) {
            count[c - 'a']--;
            if (used[c - 'a']) {
                continue;
            }
            //if ans is not empty and c < ans[n - 1] and count[ans[n - 1]] means duplicate
            while (!ans.empty() && c < ans.back() && count[ans.back() - 'a'] > 0) {
                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c - 'a'] = true;
        }
        return ans;
    }
};