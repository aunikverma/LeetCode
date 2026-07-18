class Solution {
public:
    int Mod = 1e9 + 7;
    int solve(int dice, int faces, int target) {
        // base cases
        if (target < 0) {
            return 0;
        }
        if (target == 0 && dice != 0) {
            return 0;
        }
        if (dice == 0 && target != 0) {
            return 0;
        }
        if (dice == 0 && target == 0) {
            return 1;
        }
        int ans = 0;
        for (int i = 1; i <= faces; i++) {
            ans = (ans + solve(dice - 1, faces, target - i)) % Mod;
        }
        return ans;
    }
    // int t[31][1001];
    // int solveMemo(int dice, int faces, int target) {
    //     // base cases
    //     if (target < 0) {
    //         return 0;
    //     }
    //     if (target == 0 && dice != 0) {
    //         return 0;
    //     }
    //     if (dice == 0 && target != 0) {
    //         return 0;
    //     }
    //     if (t[dice][target] != -1) {
    //         return t[dice][target];
    //     }
    //     if (dice == 0 && target == 0) {
    //         return 1;
    //     }
    //     int ans = 0;
    //     for (int i = 1; i <= faces; i++) {
    //         ans = (ans + solveMemo(dice - 1, faces, target - i)) % Mod;
    //     }
    //     return t[dice][target] = ans;
    // }

    int solveTab(int dice, int faces, int target) {
        int t[dice + 1][target + 1];
        memset(t, 0, sizeof(t));
        t[0][0] = 1;
        for (int i = 1; i <= dice; i++) {
            for (int j = 1; j <= target; j++) {
                int ans = 0;
                for (int f = 1; f <= faces; f++) {
                    if (j - f >= 0) {
                        ans = (ans + t[i - 1][j - f]) % Mod;
                    }
                    t[i][j] = ans;
                }
            }
        }
        return t[dice][target];
    }

    int solveTabSpace(int dice, int faces, int target) {
        vector<int> curr(target + 1, 0);
        vector<int> prev(target + 1, 0);
        prev[0] = 1;
        for (int i = 1; i <= dice; i++) {
            for (int j = 1; j <= target; j++) {
                int ans = 0;
                for (int f = 1; f <= faces; f++) {
                    if (j - f >= 0) {
                        ans = (ans + prev[j - f]) % Mod;
                    }
                    curr[j] = ans;
                }
            }
            prev = curr;
        }
        return curr[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // memset(t, -1, sizeof(t));
        // return solve(n, k, target);
        // return solveMemo(n, k, target);
        // return solveTab(n, k, target);
        return solveTabSpace(n, k, target);
    }
};