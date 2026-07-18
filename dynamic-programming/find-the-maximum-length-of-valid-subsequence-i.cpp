class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) return n; // all four satisfy
        bool z = nums[0] & 1;
        int a[3] = {!z, z, 1}; // even odd alternative
        for (int i = 1; i < n; i++) {
            bool x = nums[i] & 1;
            a[x & 1]++;
            if (x != z) {
                a[2]++;
                z = !z;
            }
        }
        return max({a[0], a[1], a[2]});
        // All even number
        // All odd numbers,
        // Alternating between even and odd.
    }
};