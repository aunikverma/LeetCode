class Solution {
public:
    vector<int> findAnagrams(string txt, string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a'] += 1;
        }
        int k = s.length();
        vector<int> freq1(26, 0);
        vector<int> ans;
        for (int i = 0; i < txt.length(); i++) {
            if (i - k < 0) {
                freq1[txt[i] - 'a'] += 1;
            } else if (i - k >= 0) {
                if (freq == freq1) {
                    ans.push_back(i - k);
                }
                freq1[txt[i] - 'a'] += 1;
                freq1[txt[i - k] - 'a'] -= 1;
            }
        }
        // last window
        if (freq == freq1) {
            ans.push_back(txt.length() - k);
        }
        return ans;
    }
};