class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0; // no of totalsubstrings
        int i = 0;
        while (i < s.length()) {
            int count_zero = 0, count_one = 0;
            while (s[i] == '0' && i < s.length()) {
                i++;
                count_zero++;
            }
            while (s[i] == '1' && i < s.length()) {
                i++;
                count_one++;
            }
            result += min(count_zero, count_one);
        }
        i = 0;
        while (i < s.length()) {
            int count_zero = 0, count_one = 0;
            while (s[i] == '1' && i < s.length()) {
                i++;
                count_one++;
            }
            while (s[i] == '0' && i < s.length()) {
                i++;
                count_zero++;
            }
            result += min(count_zero, count_one);
        }
        return result;
    }
};