class Solution {
public:
    string minWindow(string s, string t) {
        // base case
        if (t.length() > s.length()) {
            return "";
        }
        // sliding window
        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c] += 1;
        }

        int countReqd = t.length();
        int left = 0;
        int windowSize = INT_MAX;
        int start = -1;

        for (int right = 0; right < s.length(); right++) {
            // subtract in map
            if (mp[s[right]] > 0) {
                countReqd -= 1;
            }
            mp[s[right]] -= 1;

            // founded the window
            if (countReqd == 0) {
                // trying shrinking window
                while (countReqd <= 0) {
                    // new window
                    if (windowSize > (right - left + 1)) {
                        windowSize = (right - left + 1);
                        start = left;
                    }
                    // update in map
                    mp[s[left]] += 1;
                    // that we wanted it
                    if (mp[s[left]] > 0) {
                        countReqd += 1;
                    }
                    left += 1;
                }
            }
        }
        string ans = "";
        if (start != -1) {
            for (int i = start; i < start + windowSize; i++) {
                ans += s[i];
            }
        }
        return ans;
    }
};