class Solution {
public:
    char kthCharacter(int k) {
        string w = "a";
        while (w.length() <= k) {
            string s = "";
            for (char c : w) {
                if (c == 'z') {
                    s += 'a';
                } else {
                    c++;
                    s += c;
                }
            }
            w += s;
        }
        cout << w << " ";
        return w[k - 1];
    }
};