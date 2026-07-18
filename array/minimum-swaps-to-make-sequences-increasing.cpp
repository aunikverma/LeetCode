class Solution {
public:
    int solve(int i, vector<int>& nums1, vector<int>& nums2, bool swapped) {
        // base case
        if (i == nums1.size()) {
            return 0;
        }
        int ans = INT_MAX;
        int prev1 = (i - 1 >= 0 ? nums1[i - 1] : -1);
        int prev2 = (i - 1 >= 0 ? nums2[i - 1] : -1);
        // since we are not swapping original array
        if (swapped) {
            swap(prev1, prev2);
        }
        // no swap
        if (nums1[i] > prev1 && nums2[i] > prev2) {
            ans = solve(i + 1, nums1, nums2, 0);
        }
        if (nums1[i] > prev2 && nums2[i] > prev1) {
            ans = min(ans, 1 + solve(i + 1, nums1, nums2, 1));
        }
        return ans;
    }

    int solveMemo(int i, vector<int>& nums1, vector<int>& nums2, bool swapped,
                  vector<vector<int>>& dp) {
        // base case
        if (i == nums1.size()) {
            return 0;
        }
        if (dp[i][swapped] != -1) {
            return dp[i][swapped];
        }
        int ans = INT_MAX;
        int prev1 = (i - 1 >= 0 ? nums1[i - 1] : -1);
        int prev2 = (i - 1 >= 0 ? nums2[i - 1] : -1);
        // since we are not swapping original array
        if (swapped) {
            swap(prev1, prev2);
        }
        // no swap
        if (nums1[i] > prev1 && nums2[i] > prev2) {
            ans = solveMemo(i + 1, nums1, nums2, 0, dp);
        }
        // swap
        if (nums1[i] > prev2 && nums2[i] > prev1) {
            ans = min(ans, 1 + solveMemo(i + 1, nums1, nums2, 1, dp));
        }
        return dp[i][swapped] = ans;
    }

    int solveTab(int n, vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int s = 0; s <= 1; s++) {
                int ans = INT_MAX;
                int prev1 = (i - 1 >= 0 ? nums1[i - 1] : -1);
                int prev2 = (i - 1 >= 0 ? nums2[i - 1] : -1);
                // since we are not swapping original array
                if (s) {
                    swap(prev1, prev2);
                }
                // no swap
                if (nums1[i] > prev1 && nums2[i] > prev2) {
                    ans = min(ans, dp[i + 1][0]);
                }
                if (nums1[i] > prev2 && nums2[i] > prev1) {
                    ans = min(ans, 1 + dp[i + 1][1]);
                }
                dp[i][s] = ans;
            }
        }
        return dp[0][0];
    }

    int solveTabSpace(int n, vector<int>& nums1, vector<int>& nums2) {
        int next_swap = 0, next_noswap = 0;
        int curr_swap = 0, curr_noswap = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int s = 0; s <= 1; s++) {
                int ans = INT_MAX;
                int prev1 = (i - 1 >= 0 ? nums1[i - 1] : -1);
                int prev2 = (i - 1 >= 0 ? nums2[i - 1] : -1);
                // since we are not swapping original array
                if (s) {
                    swap(prev1, prev2);
                }
                // no swap
                if (nums1[i] > prev1 && nums2[i] > prev2) {
                    ans = min(ans, next_noswap);
                }
                if (nums1[i] > prev2 && nums2[i] > prev1) {
                    ans = min(ans, 1 + next_swap);
                }
                if (s) {
                    curr_swap = ans;
                } else {
                    curr_noswap = ans;
                }
            }
            next_swap = curr_swap;
            next_noswap = curr_noswap;
        }
        return min(curr_swap, curr_noswap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // it means that the prev indexes were swapped or not
        int n = nums1.size();
        // bool swapped = 0;
        // return solve(0, nums1, nums2, swapped);
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return solveMemo(0, nums1, nums2, swapped, dp);
        // return solveTab(n, nums1, nums2);
        return solveTabSpace(n, nums1, nums2);
    }
};