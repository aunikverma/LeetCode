class Solution {
public:
    typedef long long ll;
    int n;

    ll solve(int i, int trend, vector<int>& nums, vector<vector<ll>>& dp) {
        // out of bound
        if (i == n) {
            if (trend == 3) {
                // no more elements
                return 0;
            } else {
                // invalid path
                return (LLONG_MIN / 2);
            }
        }
        // dp table
        if (dp[i][trend] != LLONG_MIN) {
            return dp[i][trend];
        }
        ll take = (LLONG_MIN / 2);
        ll skip = (LLONG_MIN / 2);
        // skip
        if (trend == 0) {
            skip = solve(i + 1, 0, nums, dp);
        }
        // i am at trend 3 and can end now
        if (trend == 3) {
            // finish
            take = nums[i];
        }
        // other trends
        if (i + 1 < n) {
            int curr = nums[i];
            int next = nums[i + 1];
            // 0 and can be taken
            if (trend == 0 && next > curr) {
                take = max(take, curr + solve(i + 1, 1, nums, dp));
            } else if (trend == 1) {
                if (next > curr) {
                    take = max(take, curr + solve(i + 1, 1, nums, dp));
                } else if (next < curr) {
                    take = max(take, curr + solve(i + 1, 2, nums, dp));
                }
            } else if (trend == 2) {
                if (next < curr) {
                    take = max(take, curr + solve(i + 1, 2, nums, dp));
                } else if (next > curr) {
                    take = max(take, curr + solve(i + 1, 3, nums, dp));
                }
            } else if (trend == 3 && next > curr) {
                take = max(take, curr + solve(i + 1, 3, nums, dp));
            }
        }

        return dp[i][trend] = max(take, skip);
    }

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(4, LLONG_MIN));
        return solve(0, 0, nums, dp);
    }
};
// identify the diagram and we have choices using dp tables
// use trend 0,1,2,3