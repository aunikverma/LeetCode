class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = INT_MIN;
        int ind = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                ind = i;
            }
        }
        bool v = true;
        for (int i : nums) {
            if (i != maxi && 2 * i > maxi) {
                v = false;
                break;
            }
        }
        if (v) return ind;
        return -1;
    }
};