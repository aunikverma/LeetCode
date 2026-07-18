class Solution {
public:
    int size, max_cost;

    void solve(string& s, int pos, bool prev, int cost, vector<string>& ans) {
        if (pos == size && cost <= max_cost) {
            ans.push_back(s);
            return;
        }
        // try 0
        s += '0';
        solve(s, pos + 1, false, cost, ans);
        s.pop_back();

        // try 1
        if (!prev && cost + pos <= max_cost) {
            s += '1';
            solve(s, pos + 1, true, cost + pos, ans);
            s.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        size = n, max_cost = k;
        string s = "";
        vector<string> ans;
        solve(s, 0, false, 0, ans);
        return ans;
    }
};