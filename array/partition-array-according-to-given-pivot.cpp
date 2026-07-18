class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int mini = 0, equal = 0;
        for (int i : nums) {
            if (i < pivot) {
                mini += 1;
            } else if (i == pivot) {
                equal += 1;
            }
        }
        int i = 0, j = mini, k = j + equal;
        vector<int> ans(nums.size(), 0);
        for (int x : nums) {
            if (x == pivot) {
                ans[j++] = x;
            } else if (x > pivot) {
                ans[k++] = x;
            } else {
                ans[i++] = x;
            }
        }
        return ans;
    }
};