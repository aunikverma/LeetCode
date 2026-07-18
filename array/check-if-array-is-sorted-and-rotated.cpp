class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), c = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                c += 1;
            }
        }
        // Check the rotation point between last and first element
        if (nums[n - 1] > nums[0]) {
            c += 1;
        }
        // If there’s at most one drop point, it’s sorted and rotated
        // c == 0 if all the elements are equal
        return (c <= 1);
    }
};