class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prev(k, 0);
        vector<long long> ans(k, 0);

        for (int i = 0; i < n; i++) {
            // curr count at ending i
            vector<long long> curr(k, 0);
            // curr element
            curr[nums[i] % k] += 1;

            // check for prev rem
            for (int j = 0; j < k; j++) {
                int new_rem = (1LL * j * nums[i] % k) % k;
                curr[new_rem] += prev[j];
            }
            // removes copy overhead
            prev = move(curr);
            // store in ans
            for (int j = 0; j < k; j++) {
                ans[j] += prev[j];
            }
        }
        return ans;
    }
};
// we have to check all subarrays such that ans[remainder] =  product of
// subarray % k