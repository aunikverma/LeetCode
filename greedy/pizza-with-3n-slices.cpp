class Solution {
public:
    // int t[501][167];
    // int solve(int ind, int endInd, vector<int>& slices, int n) {
    //     // base case
    //     if (n == 0 || ind > endInd) {
    //         return 0;
    //     }
    //     if (t[ind][n] != -1) {
    //         return t[ind][n];
    //     }
    //     int take = slices[ind] + solve(ind + 2, endInd, slices, n - 1);
    //     int not_take = solve(ind + 1, endInd, slices, n);
    //     return t[ind][n] = max(take, not_take);
    // }

    // int solveTab(vector<int>& slices) {
    //     int k = slices.size();
    //     int t[501][170], t1[501][170];
    //     memset(t, 0, sizeof(t));
    //     memset(t1, 0, sizeof(t1));
    //     // case 1
    //     for (int i = k - 2; i >= 0; i--) {
    //         for (int n = 1; n <= k / 3; n++) {
    //             int take = slices[i] + t[i + 2][n - 1];
    //             int not_take = t[i + 1][n];
    //             t[i][n] = max(take, not_take);
    //         }
    //     }
    //     int case1 = t[0][k / 3];
    //     // case 2
    //     for (int i = k - 1; i >= 1; i--) {
    //         for (int n = 1; n <= k / 3; n++) {
    //             int take = slices[i] + t1[i + 2][n - 1];
    //             int not_take = t1[i + 1][n];
    //             t1[i][n] = max(take, not_take);
    //         }
    //     }
    //     int case2 = t1[1][k / 3];
    //     return max(case1, case2);
    // }

    int solveTabSpace(vector<int>& slices) {
        int k = slices.size();
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1, 0);
        vector<int> next(k + 1, 0);
        vector<int> prev1(k + 1, 0);
        vector<int> curr1(k + 1, 0);
        vector<int> next1(k + 1, 0);
        // case 1
        for (int i = k - 2; i >= 0; i--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[i] + next[n - 1];
                int not_take = curr[n];
                prev[n] = max(take, not_take);
            }
            next = curr;
            curr = prev;
        }
        int case1 = prev[k / 3];
        // case 2
        for (int i = k - 1; i >= 1; i--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[i] + next1[n - 1];
                int not_take = curr1[n];
                prev1[n] = max(take, not_take);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case2 = prev1[k / 3];
        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();
        // memset(t, -1, sizeof(t));
        // int case1 = solve(0, k - 2, slices, k / 3);
        // memset(t, -1, sizeof(t));
        // int case2 = solve(1, k - 1, slices, k / 3);
        // return max(case1, case2);
        // return solveTab(slices);
        return solveTabSpace(slices);
    }
};