class Solution {
public:
    // bool solve(int i, vector<int>& arr, int target) {
    //     if (i >= arr.size()) {
    //         return 0;
    //     }
    //     if (target < 0) {
    //         return 0;
    //     }
    //     if (target == 0) {
    //         return 1;
    //     }
    //     bool take = solve(i + 1, arr, target - arr[i]);
    //     bool not_take = solve(i + 1, arr, target);
    //     return (take || not_take);
    // }

    // bool solveMemo(int i, vector<int>& arr, int target,
    //                vector<vector<int>>& dp) {
    //     if (i >= arr.size()) {
    //         return 0;
    //     }
    //     if (target < 0) {
    //         return 0;
    //     }
    //     if (target == 0) {
    //         return 1;
    //     }
    //     if (dp[i][target] != -1) {
    //         return dp[i][target];
    //     }
    //     bool take = solveMemo(i + 1, arr, target - arr[i], dp);
    //     bool not_take = solveMemo(i + 1, arr, target, dp);
    //     return dp[i][target] = (take || not_take);
    // }

    // bool solveTab(int n, vector<int>& arr, int target) {
    //     vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    //     for (int i = 0; i <= n; i++) {
    //         dp[i][0] = 1;
    //     }
    //     for (int i = n - 1; i >= 0; i--) {
    //         for (int t = 0; t <= target; t++) {
    //             bool not_take = dp[i + 1][t];
    //             bool take = 0;
    //             if (t - arr[i] >= 0) {
    //                 take = dp[i + 1][t - arr[i]];
    //             }
    //             dp[i][t] = (take || not_take);
    //         }
    //     }
    //     return dp[0][target];
    // }

    bool solveTabSpace(int n, vector<int>& arr, int target) {
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);
        curr[0] = next[0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int t = 0; t <= target; t++) {
                bool not_take = next[t];
                bool take = 0;
                if (t - arr[i] >= 0) {
                    take = next[t - arr[i]];
                }
                curr[t] = (take || not_take);
            }
            next = curr;
        }
        return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if (total_sum & 1) {
            return 0;
        }
        int target = total_sum / 2;
        // return solve(0, nums, target);
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return solveMemo(0, nums, target, dp);
        return solveTabSpace(n, nums, target);
        // return solveTabSpace(n,nums,target);
    }
};