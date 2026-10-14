class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        vector<int> difference(1e5 + 1, 0);
        int max_diff = -1;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            max_diff = max(max_diff, diff);
            difference[diff]++;
        }

        int k = k1 + k2;
        int i = max_diff;
        while (i >= 1 && k > 0) {
            int countops = min(difference[i], k);
            k -= countops;
            difference[i] -= countops;
            difference[i - 1] += countops;
            i--;
        }
        long long ans = 0;
        for (long long i = 1; i <= max_diff; i++) {
            ans += (difference[i] * i * i);
        }
        return ans;
    }
};
//greedily subtracting no of ops 
//using diff count