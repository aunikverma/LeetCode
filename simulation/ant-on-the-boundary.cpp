class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count = 0;
        int sum = 0;

        for (int i : nums) {
            sum += i;
            if (sum == 0) {
                count++;
            }
        }
        return count;
    }
};