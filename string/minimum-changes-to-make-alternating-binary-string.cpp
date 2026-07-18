class Solution {
public:
    int operations(string& s, char c) {
        int steps = 0;
        if (s[0] != c) {
            steps++;
        }
        char prev = c;
        for (int i = 1; i < s.length(); i++) {
            if (prev != s[i]) {
                prev = s[i];
            } else {
                if (s[i] == '0') {
                    steps++;
                    prev = '1';
                } else {
                    steps++;
                    prev = '0';
                }
            }
        }
        return steps;
    }
    int minOperations(string s) {
        return min(operations(s, '0'), operations(s, '1'));
    }
};
// there can be two strings
//"101010" or "010101"
// find steps to convert the string to both and return min steps