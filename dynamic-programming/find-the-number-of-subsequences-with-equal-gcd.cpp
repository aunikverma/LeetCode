class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int Mod = 1e9 + 7;
        int maxi = *max_element(nums.begin(), nums.end()) + 1;
        vector<vector<int>> curr(maxi, vector<int>(maxi, 0));
        vector<vector<int>> next(maxi, vector<int>(maxi, 0));

        // base case
        for (int first = 1; first < maxi; first++) {
            next[first][first] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int first = 0; first < maxi; first++) {
                for (int second = 0; second < maxi; second++) {
                    // reset prev values
                    curr[first][second] = 0;
                    // fill ans
                    curr[first][second] +=
                        (0LL + next[first][second] +
                         next[__gcd(first, nums[i])][second] +
                         next[first][__gcd(second, nums[i])]) %
                        Mod;
                }
            }
            next = curr;
        }

        return curr[0][0];
    }
};