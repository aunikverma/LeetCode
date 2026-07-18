class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        // get the final length of ans string
        long long len = 0;

        for (char c : s) {
            if (c == '*') {
                if (len > 0) {
                    // removes ones char
                    len -= 1;
                }
            } else if (c == '%') {
                // nothing to do
                continue;
            } else if (c == '#') {
                // double len
                len <<= 1;
            } else {
                len += 1;
            }
        }

        // if k is greater
        if (k >= len) {
            return '.';
        }

        // now undo the string and len one by one
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') {
                // one char shifts
                len += 1;
            } else if (s[i] == '%') {
                // k will shift to reverse
                k = len - k - 1;
            } else if (s[i] == '#') {
                // half of len
                len >>= 1;
                if (k >= len) {
                    k -= len;
                }
            } else {
                len -= 1;
            }
            if (k == len) {
                return s[i];
            }
        }

        return '.';
    }
};