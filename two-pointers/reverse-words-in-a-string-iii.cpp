class Solution {
public:
    string reverseWords(string s) {
        int st = 0, e = 0;
        while (e <= s.size()) {
            while (e < s.size() && s[e] != ' ')
            {
                e++;
            }
            reverse(s.begin() + st, s.begin() + e); // traversing till first  word
            st = e + 1;             // then st to next word
            e = st + 1;             // and end to next space' '
        }
        return s;
    }
};