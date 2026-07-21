class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zeroBlock;
        // no of ones
        int ones = 0;
        // counted zero continuous blocks
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                int count = 0;
                while (s[i] == '0') {
                    count += 1;
                    i += 1;
                }
                i -= 1;
                zeroBlock.push_back(count);
            } else {
                ones += 1;
            }
        }
        int ans = ones;
        for (int i = 1; i < zeroBlock.size(); i++) {
            ans = max(ans, ones + zeroBlock[i - 1] + zeroBlock[i]);
        }
        return ans;
    }
};