class Solution {
private:
    bool check(vector<int>& nums, int k) {
        int c = 0;
        for (int i : nums) {
            if (i >= k) {
                c++;
            }
        }
        return (c == k);
    }

public:
    int specialArray(vector<int>& nums) {
        for (int i = 1; i <= nums.size(); i++) {
            if (check(nums,i)) {
                return i;
            }
        }
        return -1;
    }
};