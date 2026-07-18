class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // checking first increasing of decreasing
        if (nums[0] > nums[nums.size() - 1]) // decreasing
        {
            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i + 1] > nums[i]) {
                    return false;
                }
            }
        } else {//decreasing
            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i + 1] < nums[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};