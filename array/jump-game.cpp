class Solution {
public:
    bool canJump(vector<int>& nums) {
        // max_jump
        int m = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            // we cannot go forward
            if (i > m) {
                return false;
            }
            // maximum we can go
            m = max(m, i + nums[i]);
            // reached last indez
            if (m >= n - 1) {
                return true;
            }
        }
        return false;
    }
};