class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        pair<int, int> p; // even , odd
        for (int i : nums) {
            if (i % 2 == 0) {
                p.first++;
            } else {
                p.second++;
            }
        }
        int a = p.first, b = p.second;
        int k = 0;
        for (int i = 0; i < a; i++) {
            nums[k++] = 0;
        }
        for (int i = 0; i < b; i++) {
            nums[k++] = 1;
        }
        return nums;
    }
};