class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        // Iterate over possible substring lengths
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) { // Check if i is a divisor of n
                string p = s.substr(0, i);
                string r = "";
                // Construct the string by repeating the pattern
                for (int j = 0; j < n / i; j++) {
                    r += p;
                }
                // Check if the constructed string matches the original
                if (r == s) {
                    return true;
                }
            }
        }
        return false; // No valid pattern found
    }
};
