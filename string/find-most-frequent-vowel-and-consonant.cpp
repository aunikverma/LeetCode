class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> charmap(26, 0);
        for (char c : s) {
            charmap[c - 'a']++;
        }
        int maxi = INT_MIN;
        int maxi1 = INT_MIN;
        for (int i = 0; i < 26; i++) {
            if ('a' + i == 'a' || 'a' + i == 'e' || 'a' + i == 'i' ||
                'a' + i == 'o' || 'a' + i == 'u') {
                maxi = max(maxi, charmap[i]);
            } else {
                maxi1 = max(maxi1, charmap[i]);
            }
        }
        return (maxi + maxi1);
    }
};