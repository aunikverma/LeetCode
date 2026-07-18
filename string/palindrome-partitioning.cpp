class Solution {
public:
    int n;
    bool palindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void solve(string& s, int ind, vector<string> curr,
               vector<vector<string>>& ans) {
        if (ind == n) {
            ans.push_back(curr);
            return;
        }

        for (int i = ind; i < n; i++) {
            if (palindrome(s, ind, i)) {
                curr.push_back(s.substr(ind, i - ind + 1));
                solve(s, i + 1, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, 0, curr, ans);
        return ans;
    }
};