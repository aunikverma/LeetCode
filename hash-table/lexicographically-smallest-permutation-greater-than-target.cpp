class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end());
        // first one
        if (s > target) {
            return s;
        }
        while (next_permutation(s.begin(), s.end())) {
            if (s > target) {
                return s;
            }
        }
        return "";
    }
};