class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        vector<int> suffixMin(n, 0);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(nums[i], maxi);
            if (maxi - suffixMin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};