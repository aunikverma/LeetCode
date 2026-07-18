class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, k = 0;
        while (i < n) {
            nums[k] = nums[i];
            int j = i;
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            k++;
            i = j;
        }
        nums.resize(k);
        return (k);
    }
};