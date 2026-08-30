class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        // only one element
        if (n == 1) {
            return n;
        }
        int min_ind = -1;
        int max_ind = -1;
        int mini = INT_MAX, maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                min_ind = i;
            }
            if (nums[i] > maxi) {
                maxi = nums[i];
                max_ind = i;
            }
        }
        int ans = n;
        if (max_ind > min_ind) {
            ans = min(ans, max_ind + 1);
            ans = min(ans, n - min_ind);
            ans = min(ans, min_ind + 1 + (n - max_ind));
        }
        if (min_ind > max_ind) {
            ans = min(ans, min_ind + 1);
            ans = min(ans, n - max_ind);
            ans = min(ans, max_ind + 1 + (n - min_ind));
        }
        return ans;
    }
};