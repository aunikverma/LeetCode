class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count = 0;
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
                count++;
            }
            if (s[i] != t[j]) {
                j++;
            }
        }
        return (count == s.size());
    }
};