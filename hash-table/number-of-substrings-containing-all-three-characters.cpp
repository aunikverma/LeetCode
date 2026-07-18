class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        vector<int> freq(3, 0);
        int l = 0, r, n = s.length();

        for (r = 0; r < n; r++) {
            freq[s[r] - 'a'] += 1;
            // shifting l
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += (n - r);
                freq[s[l] - 'a'] -= 1;
                l++;
            }
        }
        return count;
    }
};