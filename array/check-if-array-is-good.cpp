class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi = 0;
        for (int i : nums) {
            maxi = max(maxi, i);
        }
        vector<int> freq(maxi + 1, 0);
        for (int i : nums) {
            freq[i] += 1;
        }
        for (int i = 1; i < freq.size(); i++) {
            if (i == maxi && freq[i] != 2) {
                return false;
            }
            if (i < maxi && freq[i] != 1) {
                return false;
            }
        }
        return true;
    }
};