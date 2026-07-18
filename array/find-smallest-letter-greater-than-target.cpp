class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        set<char> s(letters.begin(), letters.end());
        char ans = letters[0];
        auto it = s.upper_bound(target); // Find the next letter strictly greater than`target`

        // If we reach the end of the set, wrap around to the smallest element
        if (it != s.end()) {
            return *it;
        } else {
            return ans; // Wrap around to the smallest letter
        }
    }
};
