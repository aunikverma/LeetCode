class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> v(101);
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]] = 1;
        }
        int c = 0;
        for (int i = 0; i <= 100; i++) {
            if (v[i]) {
                if (i < k)
                    return -1;
                else if (i > k)
                    c++;
            }
        }
        return c;
    }
};