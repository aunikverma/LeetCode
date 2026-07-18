class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0;
        vector<int> freq(n + 1, 0);
        for (int i : nums) {
            freq[i]++;
        }
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) {
                b = i;
            }
            if (freq[i] == 2) {
                a = i;
            }
        }
        return {a, b};
    }
};