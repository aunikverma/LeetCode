class Solution {
public:
    int longestPalindrome(string s) {
        if (s.length() == 1)
            return 1;

        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        int ans = 0;
        bool h = false;

        for (auto& v : mp) {
            if (v.second % 2 == 0) {
                ans += v.second; // Add even counts directly
            } else {
                ans += v.second - 1; // Add the largest even portion of the odd count
                h = true; // Mark that we encountered an odd count
            }
        }

        if (h) {
            ans += 1; // Add 1 for the center character if there's any odd count
        }

        return ans;
    }
};
