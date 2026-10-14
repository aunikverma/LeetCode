class Solution {
public:
    void solve(int i, int bal, string& path, string& s,
               unordered_map<int, set<string>>& ans) {
        if (i >= s.length()) {
            if (bal == 0 && !path.empty()) {
                // no of removals
                int change = (s.length() - path.length());
                ans[change].insert(path);
            }
            return;
        }
        if (bal < 0) {
            return;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            path.push_back(s[i]);
            solve(i + 1, bal, path, s, ans);
            path.pop_back();
        } else {
            // skip
            solve(i + 1, bal, path, s, ans);

            // take
            bal += (s[i] == '(' ? 1 : -1);
            path.push_back(s[i]);
            solve(i + 1, bal, path, s, ans);
            path.pop_back();
            bal += (s[i] == '(' ? -1 : 1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_map<int, set<string>> ans;
        string path = "";
        solve(0, 0, path, s, ans);
        // minimum removals
        int mini = INT_MAX;
        for (auto& v : ans) {
            mini = min(mini, v.first);
        }
        // store ans
        vector<string> res;
        for (auto& i : ans[mini]) {
            res.push_back(i);
        }
        if (res.empty()) {
            res.push_back("");
        }
        return res;
    }
};