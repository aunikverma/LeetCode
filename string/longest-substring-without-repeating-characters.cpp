class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> s1;
        int st = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            while (s1.find(s[i]) != s1.end()) {
                s1.erase(s[st]);
                st++;
            }
            s1.insert(s[i]);
            ans = max(ans, i - st + 1);
        }
        return ans;
    }
};