class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int M = 1e9 + 7;
        int ans = 0;
        int left = 0;
        int right = nums.size() - 1;
        sort(nums.begin(), nums.end());
        vector<int> vec(nums.size());
        vec[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            vec[i] = (vec[i - 1] * 2) % M;
        }
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                int diff = right - left;
                ans = (ans + vec[diff]) % M;
                left++;
            } else
                right--;
        }
        return ans;
    }
};