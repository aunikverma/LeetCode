class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> freq(26, 0);
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                freq[c - 'a'] += 1;
            } else {
                ans += 1;
            }
        }
        sort(freq.rbegin(), freq.rend());
        int push = 1;
        for (int i = 0; i < 26; i++) {
            push = (i / 8) + 1;
            ans += freq[i] * push;
        }
        return ans;
    }
};