class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(52, 0);
        for (char c : word) {
            if (isupper(c)) {
                freq[c - 'A']++;
            } else {
                freq[c - 'a' + 26]++;
            }
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0 && freq[i + 26] > 0) {
                count++;
            }
        }
        return count;
    }
};