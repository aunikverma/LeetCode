class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> s;
        string ans = "";
        for (int i = 1; i <= n; i++) {
            s.push_back(i);
        }
        if (k == 1) {
            for (int i : s) {
                ans += to_string(i);
            }
            return ans;
        } else {
            k--;
            while (k--) {
                next_permutation(s.begin(), s.end());
            }
            for (int i : s) {
                ans += to_string(i);
            }
            return ans;
        }
        return "0";
    }
};