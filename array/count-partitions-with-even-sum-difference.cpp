class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int prev = 0, count = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size() - 1; i++) {
            prev += nums[i];
            int diff = abs(sum - (2 * prev));
            if (diff % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};