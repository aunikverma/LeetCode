class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(9, 0);
        while (n > 0) {
            int r = n % 10;
            if (r != 0) {
                freq[r - 1] += 1;
            }
            n /= 10;
        }
        int ans = 0;
        for (int i = 0; i < 9; i++) {
            ans += (i + 1) * freq[i];
        }
        return ans;
    }
};