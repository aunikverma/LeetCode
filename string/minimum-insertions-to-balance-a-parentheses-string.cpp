class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int ans = 0;
        int open = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            }
            // closing
            else {
                if (i + 1 == n || s[i + 1] != ')') {
                    if (open == 0) {
                        // one closing and opening
                        ans += 2;
                    } else {
                        // one closing
                        ans++;
                        open--;
                    }
                } else if (s[i + 1] == ')') {
                    if (open == 0) {
                        // one opening needed
                        ans++;
                    } else {
                        open--;
                    }
                    // consume second closing
                    i++;
                }
            }
        }
        // handling rest open
        if (open > 0) {
            ans += (open << 1);
        }
        return ans;
    }
};