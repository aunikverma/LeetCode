class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        int M = 1e9 + 7;

        vector<int> count(32, 0);

        // stored bits of all nums in count
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            for (int j = 0; j < 32; j++) {
                // check if that bit is 1
                if (val & (1 << j)) {
                    count[j]++;
                }
            }
        }

        long long ans = 0;
        while (k--) {
            long long curr = 0;
            for (int i = 0; i < 32; i++) {
                if (count[i] > 0) {
                    count[i]--;
                    // make that bit 1
                    curr = (curr | (1 << i));
                }
            }
            ans = (ans + (curr * curr) % M) % M;
        }
        return (int)ans;
    }
};
// since sum of elements at all changes remains constant
// we will greedily make all k largest elements that we can form