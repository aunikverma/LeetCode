class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        // sort half part
        vector<int> freq(26, 0);
        for (int i = 0; i < n / 2; i++) {
            freq[s[i] - 'a'] += 1;
        }
        int k = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                for (int j = 0; j < freq[i]; j++) {
                    s[k++] = ('a' + i);
                }
            }
        }
        // making similar
        int l = 0, r = s.length() - 1;
        while (l < r) {
            s[r] = s[l];
            l++;
            r--;
        }
        return s;
    }
};