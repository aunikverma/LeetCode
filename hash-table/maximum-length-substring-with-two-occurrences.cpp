class Solution {
public:
    int maximumLengthSubstring(string s) {
        int length = -1;
        unordered_map<int, int> mp;

        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            mp[s[right]] += 1;
            while (mp[s[right]] > 2) {
                mp[s[left]] -= 1;
                left++;
            }
            length = max(length, (right - left + 1));
        }
        return length;
    }
};