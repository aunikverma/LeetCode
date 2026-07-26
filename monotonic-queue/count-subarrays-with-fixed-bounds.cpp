class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minpos = -1, maxpos = -1, culprit = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                culprit = i;
            }
            if (nums[i] == minK) {
                minpos = i;
            }
            if (nums[i] == maxK) {
                maxpos = i;
            }
            int smaller = min(minpos, maxpos);
            int temp = smaller - culprit;
            ans += (temp <= 0 ? 0 : temp);
        }
        return ans;
    }
};