class Solution {
public:
    int maximumLengthSubstring(string s) {
        int length = -1;
        vector<int> mp(26, 0);

        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            mp[s[right] - 'a'] += 1;
            while (mp[s[right] - 'a'] > 2) {
                mp[s[left] - 'a'] -= 1;
                left++;
            }
            length = max(length, (right - left + 1));
        }
        return length;
    }
};