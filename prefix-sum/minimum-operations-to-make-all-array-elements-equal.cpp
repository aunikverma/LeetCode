class Solution {
public:
    int find_ind(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= k) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> prefix_sum(n, 0);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = (nums[i] + prefix_sum[i - 1]);
        }
        vector<long long> ans;
        for (int q : queries) {
            int ind = find_ind(nums, q);
            long long left = 0, right = 0;
            if (ind >= 0) {
                left = (1LL * q * (ind + 1)) - prefix_sum[ind];
            }
            if (ind < n - 1) {
                right = (prefix_sum[n - 1] - (ind >= 0 ? prefix_sum[ind] : 0)) -
                        (1LL * q * (n - ind - 1));
            }
            ans.push_back(left + right);
        }
        return ans;
    }
};