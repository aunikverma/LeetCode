class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, max_length = 0, n = nums.size();
        for (int j = 0; j < n; j++) {
            // i++ when nums[j](max till now) > (min)i * k
            if ((long long)nums[i] * k < (long long)nums[j]) {
                i++;
            }
            max_length = max(max_length, j - i + 1);
        }
        return (n - max_length);
    }
};