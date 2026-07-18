class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        int first_min = INT_MAX, second_min = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < first_min) {
                second_min = first_min;
                first_min = nums[i];
            }
            else if (nums[i] < second_min) {
                second_min = nums[i];
            }
        }
        return (ans + first_min + second_min);
    }
};
//first_min to second, if lower value found then first_min
//if value less than second_min update second_min