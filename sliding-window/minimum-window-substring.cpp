class Solution {
public:
    string minWindow(string s, string t) {
        // base case
        if (t.length() > s.length()) {
            return "";
        }

        // mapping of t
        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c] += 1;
        }
        int countReqd = t.length();
        int left = 0;
        int windowSize = INT_MAX;
        int start = -1;

        for (int right = 0; right < s.length(); right++) {
            // subtracting if found
            if (mp[s[right]] > 0) {
                countReqd -= 1;
            }
            mp[s[right]] -= 1;

            // if windown founded
            if (countReqd == 0) {
                // trying shrinking windowSize
                while (countReqd <= 0) {
                    if (windowSize > (right - left + 1)) {
                        windowSize = right - left + 1;
                        start = left;
                    }
                    // adding char
                    mp[s[left]] += 1;
                    if (mp[s[left]] > 0) {
                        countReqd += 1;
                    }
                    left += 1;
                }
            }
        }
        return (start == -1 ? "" : s.substr(start, windowSize));
    }
};