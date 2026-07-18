class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i : nums) {
            mini = min(i, mini);
            maxi = max(i, maxi);
        }
        for (int i = 0; i < k; i++) {
            maxi -= 1;
            mini += 1;
            // there will be a value where they be equal
            if (mini > maxi) {
                return 0;
            }
        }
        return (maxi - mini);
    }
};