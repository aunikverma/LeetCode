class Solution {
public:
    // int t[101];
    // int solve(int i, int endInd, vector<int>& nums) {
    //     if (i > endInd) {
    //         return 0;
    //     }
    //     if (t[i] != -1) {
    //         return t[i];
    //     }
    //     int take = nums[i] + solve(i + 2, endInd, nums);
    //     int not_take = solve(i + 1, endInd, nums);
    //     return t[i] = max(take, not_take);
    // }

    int solveTab(vector<int>& nums) {
        int n = nums.size();
        int prev = 0, next = 0, curr = 0;
        int prev1 = 0, next1 = 0, curr1 = 0;
        for (int i = n - 2; i >= 0; i--) {
            int take = nums[i] + next;
            int not_take = curr;
            prev = max(take, not_take);
            next = curr;
            curr = prev;
        }
        for (int i = n - 1; i >= 1; i--) {
            int take = nums[i] + next1;
            int not_take = curr1;
            prev1 = max(take, not_take);
            next1 = curr1;
            curr1 = prev1;
        }
        return max(curr, curr1);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        // // rob 0th house
        // memset(t, -1, sizeof(t));
        // int case1 = solve(0, n - 2, nums);
        // // rob 1st house
        // memset(t, -1, sizeof(t));
        // int case2 = solve(1, n - 1, nums);
        // return max(case1, case2);
        return solveTab(nums);
    }
};