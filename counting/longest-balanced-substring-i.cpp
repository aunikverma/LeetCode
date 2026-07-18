class Solution {
public:
    bool check_balance(vector<int>& freq) {
        int common = 0;
        for (int i : freq) {
            if (i == 0) {
                continue;
            }
            if (common == 0) {
                common = i;
            } else if (common != i) {
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        if (s.length() == 1) {
            return 1;
        }
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);
            freq[s[i] - 'a']++;
            for (int j = i + 1; j < s.length(); j++) {
                freq[s[j] - 'a']++;
                if (check_balance(freq)) {
                    ans = max(ans, j - i + 1);
                }
            }
            if (ans == s.length() - 1) {
                break;
            }
        }
        return ans;
    }
};