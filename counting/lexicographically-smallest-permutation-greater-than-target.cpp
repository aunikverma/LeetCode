class Solution {
public:
    string ans = "";

    bool solve(string& curr, vector<int>& count, string& target, int i,
               bool greater) {
        if (i == target.length()) {
            if (greater) {
                ans = curr;
                return true;
            }
            return false;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (count[c - 'a'] == 0) {
                continue;
            }
            if (greater == false && c < target[i]) {
                continue;
            }

            bool isGreater = (greater || c > target[i]);
            // push
            curr.push_back(c);
            count[c - 'a'] -= 1;

            if (solve(curr, count, target, i + 1, isGreater)) {
                return true;
            }
            // pop
            curr.pop_back();
            count[c - 'a'] += 1;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a'] += 1;
        }
        string curr;
        solve(curr, count, target, 0, false);
        return ans;
    }
};