class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int i = 0;
        int j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else if ((s1[i] == 'z' && s2[j] == 'a') || (++s1[i] == s2[j])) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return (j == s2.size());
    }
};