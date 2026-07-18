class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;

        int a = 0;

        while (i < j) {
            int s = nums[i] + nums[j];

            if (s == k) {
                i++;
                j--;
                a++;
            } else if (s < k) {
                i++;
            } else {
                j--;
            }
        }
        return a;
    }
};