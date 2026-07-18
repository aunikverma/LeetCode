class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> v(nums.size() + 1);
        for (int i : nums) {
            v[i]++;//creating frequency array
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                return i;//where frequency is zero return index
            }
        }
        return 0;
    }
};